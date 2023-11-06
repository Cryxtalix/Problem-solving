#ifndef INPUT
#define INPUT

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct {
        uint8_t data[9][9];
}Board;

void read_board(Board *my_board, char *path);

#endif //INPUT