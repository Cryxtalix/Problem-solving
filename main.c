#include "lib/lib.h"

Board myBoard = {0};

int main(int argc, char *argv[])
{
        read_board(myBoard, "./input.txt");

        write_board(myBoard);

        printf("%d\n", check_board(myBoard));

        return 0;
}