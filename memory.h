#ifndef MEMORY_H
#define MEMORY_H

char **allocate_board(int rows, int columns);

void free_board(char **board, int rows, int columns);

#endif
