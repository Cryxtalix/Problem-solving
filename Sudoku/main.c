#include "lib/lib.h"

Board myBoard = {0};

/**
 * @brief Returns 1 number found in array, 0 if not found
 * 
 * @param num 
 * @param arr 
 * @return true 
 * @return false 
 */
bool search(int num, Missing_Numbers *arr) {
        for (int i = 0; i < arr->Amount; i++) {
                if (num == arr->Array[i]) {
                        return true;
                }
        }
        return false;
}

void find_repeated_num(Missing_Numbers *one, Missing_Numbers *two, Missing_Numbers *three, Missing_Numbers *output)
{
        int cnt = 0;
        int repeats[9] = {0};

        for (int num = 1; num < 10; num++) {
                bool result = search(num, one);
                result &= search(num, two); //bitwise AND
                result &= search(num, three);
                if (result == true) {
                        repeats[cnt] = num;
                        cnt += 1;
                }
        }

        output->Amount = cnt;
        for (int i = 0; i < 9; i++) {
                output->Array[i] = repeats[i];
        }
}

int search_pass(Board myBoard)
{
        Group tmp1;
        Group tmp2;
        Group tmp3;

        Missing_Numbers miss1;
        Missing_Numbers miss2;
        Missing_Numbers miss3;

        Missing_Numbers found_values;
        int max_solutions = 100;

        for (int row = 0; row < 9; row++) {
                for (int column = 0; column < 9; column++) {
                        if (myBoard[column][row] == 0) {
                                get_column(column, myBoard, tmp1);
                                get_missing_numbers(tmp1, &miss1);

                                get_row(row, myBoard, tmp2);
                                get_missing_numbers(tmp2, &miss2);

                                get_3x3(get_grid_num(column, row), myBoard, tmp3);
                                get_missing_numbers(tmp3, &miss3);

                                find_repeated_num(&miss1, &miss2, &miss3, &found_values);

                                // Update the highest number of solutions
                                if (found_values.Amount < max_solutions) {
                                        max_solutions = found_values.Amount;
                                }

                                if (found_values.Amount == 1) { // Found solution for cell
                                        myBoard[column][row] = found_values.Array[0];
                                }
                        }
                }
        }
        return max_solutions;
}

// Fills a single multi-solution cell
int mutli_solution_pass(Board board, int max_soln, int iter_num)
{
        Group tmp1;
        Group tmp2;
        Group tmp3;

        Missing_Numbers miss1;
        Missing_Numbers miss2;
        Missing_Numbers miss3;

        Missing_Numbers found_values;

        for (int row = 0; row < 9; row++) {
                for (int column = 0; column < 9; column++) {
                        if (board[column][row] == 0) {
                                get_column(column, board, tmp1);
                                get_missing_numbers(tmp1, &miss1);

                                get_row(row, board, tmp2);
                                get_missing_numbers(tmp2, &miss2);

                                get_3x3(get_grid_num(column, row), board, tmp3);
                                get_missing_numbers(tmp3, &miss3);

                                find_repeated_num(&miss1, &miss2, &miss3, &found_values);

                                // Choose one of the possible solutions to fill
                                if (found_values.Amount == max_soln) {
                                        board[column][row] = found_values.Array[iter_num];
                                        return 0;
                                }
                        }
                }
        }
}

// Nasty recursive function damn
void solve_multi_solution(Board board, const char *filename, int recursion) 
{
        int max_solutions = search_pass(board);

        Board new_board;
        for (int i = 0; i < max_solutions; i++) {

                // Copy board to the new board
                for (int row = 0; row < 9; row++) {
                        for (int column = 0; column < 9; column++) {
                                new_board[column][row] = board[column][row];
                        }
                }

                // Fill cell with maximum number of solutions, selecting based on current loop index
                mutli_solution_pass(new_board, max_solutions, i);

                // Solving loop until no further improvement
                int empty_cell_count = get_total_empty_cells(new_board);
                int new_emtpy_cell_count = 81;
                do {
                        empty_cell_count = new_emtpy_cell_count;
                        search_pass(new_board);
                        new_emtpy_cell_count = get_total_empty_cells(new_board);
                } while(check_board(new_board) == 0 && new_emtpy_cell_count < empty_cell_count);

                // Check if board is solved
                if (check_board(new_board) == 1) {
                        char name[50];
                        snprintf(name, 50, "gen%d_%d_%s", recursion, i, filename);
                        write_board(new_board, name);
                }

                // If board is still unsolved, perform nasty recursion
                if (check_board(new_board) == 0) {
                        solve_multi_solution(new_board, filename, recursion += 1);
                }
        }
}

int main(int argc, char *argv[])
{
        const char *filename = "input.txt";
        char path[50];
        snprintf(path, 50, "./%s", filename);
        read_board(myBoard, path);

        // Solving loop until empty cell counts no longer reduce
        int empty_cell_count = get_total_empty_cells(myBoard);
        int new_emtpy_cell_count = 81;
        do {
                empty_cell_count = new_emtpy_cell_count;
                search_pass(myBoard);
                new_emtpy_cell_count = get_total_empty_cells(myBoard);
        } while(check_board(myBoard) == 0 && new_emtpy_cell_count < empty_cell_count);

        // Board with single solution has been solved
        if (check_board(myBoard) == 1) {
                printf("Puzzle solved. Please check output folder for printout.\n");
                char name[50];
                snprintf(name, 50, "s_%s", filename);
                write_board(myBoard, name);
                return 0;
        }

        // If board still has empty cells,
        solve_multi_solution(myBoard, filename, 1);

        printf("Please check output folder. If there are no txt files, there may be no solution.\n");
        return 0;
}