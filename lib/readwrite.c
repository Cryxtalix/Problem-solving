#include "lib.h"

void read_board(Board my_board, char *path)
{
        FILE *fp = fopen(path, "r");

        if (fp == NULL) {
                perror("Error reading board");
        }

        for (int row = 0; row < 9; row++) {
                for (int column = 0; column < 10; column++) { // 10 to account for newline char
                        char tmp[2] = {'\0'};
                        tmp[0] = fgetc(fp);

                        if (tmp[0] == '\n') {
                                continue;
                        } else {
                                my_board[column][row] = atoi(tmp);
                        }
                        
                }
        }

        fclose(fp);
}

void write_board(Board my_board) {
        FILE *fp = fopen("output/solution.txt", "w");
        if (fp == NULL) {
                perror("Error writing board");
        }

        for (int row = 0; row < 9; row++) {
                for (int column = 0; column < 9; column++) {
                        fprintf(fp, "%d", my_board[column][row]);
                }
                fprintf(fp, "\n");
        }

        fclose(fp);
}

void print_board_terminal(Board my_board)
{
        for (int row = 0; row < 9; row++) {
                for (int column = 0; column < 9; column++) {
                        printf("%d", my_board[column][row]);
                }
                printf("\n");
        }
}