#include "readwrite.h"

void read_board(Board *my_board, char *path)
{
        FILE *fp = fopen(path, "r");

        if (fp == NULL) {
                int errnum = errno;
                fprintf(stderr, "Value of errno: %d\n", errno);
                perror("Error printed by perror");
                fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));
        }

        for (int row = 0; row < 9; row++) {
                for (int column = 0; column < 10; column++) { // 10 to account for newline char
                        char tmp[2] = {'\0'};
                        tmp[0] = fgetc(fp);

                        if (tmp[0] == '\n') {
                                continue;
                        } else {
                                my_board->data[column][row] = atoi(tmp);
                        }
                        
                }
        }

        fclose(fp);
}