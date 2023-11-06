#include "lib/lib.h"

Board myBoard = {0};

int main(int argc, char *argv[])
{
        read_board(myBoard, "./input.txt");

        write_board(myBoard);

        Group grp;
        get_row(1, myBoard, grp);

        Missing_Numbers test;
        get_missing_numbers(grp, &test);

        printf("There are %d missing numbers.\n", test.Amount);

        for (int i = 0; i < test.Amount; i++) {
                printf("%d", test.Array[i]);
        }

        return 0;
}