#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

char **allocate_board(int rows, int columns) {
	char **board = malloc(rows * sizeof(char *));

	for(int i = 0; i < rows; i++) {
		board[i] = malloc(2 * columns * sizeof(char));
	}
	return board;
}

void free_board(char **board, int rows, int columns) {
	for(int i = 0; i < rows; i++) {
		free(board[i]);
	}
	free(board);
}


