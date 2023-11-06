#ifndef LIBRARY
#define LIBRARY

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

//#define DEBUG 1

typedef uint8_t Board[9][9];
typedef uint8_t Group[9];
typedef struct Missing_Numbers{
        uint8_t Amount;
        uint8_t Array[9];
}Missing_Numbers;

// Input / Output
void read_board(Board my_board, char *path);
void write_board(Board my_board);
void print_board_terminal(Board my_board);

// Get groups
void get_column(int column_num, Board myBoard, Group arr);
void get_row(int row_num, Board myBoard, Group arr);
void get_9x9(int grid_num, Board myBoard, Group arr);
int get_grid_num(int column, int row);

// Check board
bool is_invalid(Group my_group);
bool is_filled(Group my_group);
void get_missing_numbers(Group my_group, Missing_Numbers *missing);
int check_board(Board my_board);
int get_total_empty_cells(Board my_board);

#endif //LIBRARY