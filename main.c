#include "lib/lib.h"

int main(int argc, char *argv[])
{
        Board myBoard = {0};

        read_board(myBoard, "./input.txt");

        write_board(myBoard);

        return 0;
}