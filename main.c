#include <stdio.h>
#include <stdint.h>
#include "readwrite/readwrite.h"

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

        for (int column = 0; column < 9; column++) {
                for (int row = 0; row < 9; row++) {
                        printf("%d", myBoard->data[row][column]);
                }
                printf("\n");
        }
        printf("\n");

        free(myBoard);
        return 0;
}