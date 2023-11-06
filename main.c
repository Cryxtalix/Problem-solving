#include "lib/lib.h"

Board myBoard = {0};

void search_pass(void)
{
        Group tmp1;
        Group tmp2;
        Group tmp3;
        
        for (int row = 0; row < 9; row++) {
                for (int column = 0; column < 9; column++) {
                        if (myBoard[column][row] == 0) {
                                get_column(column, myBoard, tmp1);
                                get_row(row, myBoard, tmp2);
                                get_9x9(get_grid_num(column, row), myBoard, tmp1);
                        }
                }
        }
}

int main(int argc, char *argv[])
{
        read_board(myBoard, "./input.txt");

        /* while(check_board(myBoard) == 0) {
                search_pass();
        } */

        printf("%d\n", get_grid_num(2, 6));

        return 0;
}