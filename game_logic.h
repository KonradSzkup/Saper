#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

int flag_cell(char **board, int rows, int columns, int x, int y);
int reveal_cell(char **board, int rows, int columns, int x, int y);
int is_game_won(char **board, int rows, int columns, int mines, int counter);

#endif
