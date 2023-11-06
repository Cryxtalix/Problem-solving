#include "lib/lib.h"

int main(int argc, char *argv[])
{
        // Allocate board
        Board* myBoard = malloc(sizeof(Board));
        memset(myBoard, 0, sizeof(myBoard));

        if (myBoard == NULL) {
                perror("Memory allocation failed");
                return 1;
        }

        read_board(myBoard, "./input.txt");

        write_board(myBoard);

        free(myBoard);
        return 0;
}