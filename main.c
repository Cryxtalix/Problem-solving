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

void search_pass(void)
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
                        if (myBoard[column][row] == 0) {
                                get_column(column, myBoard, tmp1);
                                get_missing_numbers(tmp1, &miss1);

                                get_row(row, myBoard, tmp2);
                                get_missing_numbers(tmp2, &miss2);

                                get_9x9(get_grid_num(column, row), myBoard, tmp3);
                                get_missing_numbers(tmp3, &miss3);

                                find_repeated_num(&miss1, &miss2, &miss3, &found_values);

                                if (found_values.Amount == 1) { // Found solution for cell
                                        myBoard[column][row] = found_values.Array[0];
                                }
                        }
                }
        }
}

int main(int argc, char *argv[])
{
        read_board(myBoard, "./input.txt");
        int empty_cell_count = get_total_empty_cells(myBoard);
        int new_emtpy_cell_count = 81;
        

        do {
                empty_cell_count = new_emtpy_cell_count;
                search_pass();
                new_emtpy_cell_count = get_total_empty_cells(myBoard);
        } while(check_board(myBoard) == 0 && new_emtpy_cell_count < empty_cell_count);

        if (check_board(myBoard) == 1) {
                printf("Puzzle solved! Check the output folder for the txt file.\n");
                write_board(myBoard);
        } 

#ifdef DEBUG
        else {
                print_board_terminal(myBoard);
        }
#endif //DEBUG

        return 0;
}