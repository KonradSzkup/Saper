#ifndef INPUT_H
#define INPUT_H

int get_user_input(int *x, int *y, char *action, int rows, int columns);
int get_game_mode(int *rows, int *columns, int *mines, int *multiplier, char *option);
int option_4(int *rows, int *columns, int *mines); 

#endif
