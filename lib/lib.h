#ifndef LIBRARY
#define LIBRARY

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef uint8_t Board[9][9];

void read_board(Board my_board, char *path);

void write_board(Board my_board);

#endif //LIBRARY