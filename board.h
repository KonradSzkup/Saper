#ifndef BOARD_H
#define BOARD_H

void init_board(char **board, int rows, int colums, int mines);

void place_mines(char **board, int rows, int columns, int mines);

void calculate_adjancent_mines(char **board, int rows, int columns);

void print_board(char **board, int rows, int columns);

#endif
