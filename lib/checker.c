#include "lib.h"

bool is_invalid(Group my_group)
{
        // Check if there are any repeat numbers
        bool tmp[9] = {0};
        for (int i = 0; i < 9; i++) {
                uint8_t num = my_group[i];
                if (num != 0) {
                        if (tmp[num - 1] == 0) {
                                tmp[num - 1] = 1;
                        } else {
                                return 1;
                        }
                }
        }
        return 0;
}

bool is_filled(Group my_group)
{
        for (int i = 0; i < 9; i++) {
                if (my_group[i] == 0) {
                        return 0;
                }
        }
        return 1;
}

void get_missing_numbers(Group my_group, Missing_Numbers *missing)
{
        uint8_t cnt = 0;
        uint8_t miss_arr[9] = {0};

        for (int i = 1; i < 10; i++) {
                bool found = 0;
                for (int idx = 0; idx < 9; idx++) {
                        if (my_group[idx] == i) {
                                found = 1;
                        }
                }
                if (found == 0) {
                        miss_arr[cnt] = i;
                        cnt += 1;
                }
        }
        
        missing->Amount = cnt;
        for (int i = 0; i < 9; i++) {
                missing->Array[i] = miss_arr[i];
        }
}

void get_column(int column_num, Board myBoard, Group arr)
{
        for (int i = 0; i < 9; i++) {
                arr[i] = myBoard[column_num][i];
        }
}

void get_row(int row_num, Board myBoard, Group arr)
{
        for (int i = 0; i < 9; i++) {
                arr[i] = myBoard[i][row_num];
        }
}

/**
 * @brief Get the numbers within the 9x9 square.
 * From left to right, top to bottom, counting from 0.
 * 
 * @param grid_num 
 * @param myBoard 
 * @param arr 
 */
void get_9x9(int grid_num, Board myBoard, Group arr)
{
        // Get coordinates
        const int coordinates[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
        const int *columns = coordinates[grid_num % 3];
        const int *rows = coordinates[grid_num / 3];

        // Loop
        int cnt = 0;
        for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                        arr[cnt] = myBoard[columns[y]][rows[x]];
                        cnt += 1;
                }
        }
}

/**
 * @brief Get grid number from coordinates
 * 
 * @param column 
 * @param row 
 * @return int 
 */
int get_grid_num(int column, int row)
{
        const int coordinates[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
        int grid_row = row / 3;
        int grid_col = column / 3;

        return coordinates[grid_row][grid_col];
}

/**
 * @brief Checks state of the board
 * 
 * @param my_board 
 * @return Int 0: Incomplete, 1: Complete, -1: Invalid
 */
int check_board(Board my_board)
{
        Group tmp_grp;
        uint8_t score = 0;

        // Check columns
        for (int i = 0; i < 9; i++) {
                get_column(i, my_board, tmp_grp);
                if (is_invalid(tmp_grp) == 1) {
                        goto Invalid;
                }
                if (is_filled(tmp_grp) == 1) {
                        score += 1;
                }
        }

        // Check rows
        for (int i = 0; i < 9; i++) {
                get_row(i, my_board, tmp_grp);
                if (is_invalid(tmp_grp) == 1) {
                        goto Invalid;
                }
                if (is_filled(tmp_grp) == 1) {
                        score += 1;
                }
        }

        // Check 9x9
        for (int i = 0; i < 9; i++) {
                get_9x9(i, my_board, tmp_grp);
                if (is_invalid(tmp_grp) == 1) {
                        goto Invalid;
                }
                if (is_filled(tmp_grp) == 1) {
                        score += 1;
                }
        }

        if (score < 27) {
                return 0;
        } else {
                return 1;
        }

Invalid:
        perror("Board is invalid.");
        return -1;
}