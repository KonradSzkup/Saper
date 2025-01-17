#include <stdio.h>
#include <stdlib.h>
#include "game_logic.h"
#include "memory.h"
#include "board.h"

int read_from_file(char *filename) {
	
	FILE *in = fopen(filename, "r");

	if(in == NULL) {
		fprintf(stderr, "Nie udalo sie otworzyc pliku");
		return -1;
	}

	int rows;
	int columns;
	int mines = 0;
	fscanf(in, "%d %d", &rows, &columns);

	char **board = allocate_board(rows, columns);
	char c;

	for(int x = 0; x < rows; x++) {
		for(int y = 0; y < columns; y++) {
			fscanf(in, " %c", &c);
			if(c == '*')
				mines++;
			board[x][y] = c;
			board[x][y + columns] = 'n';		
		}
	}
	char action;
	int x;
	int y;
	int counter;
	int right_moves = 0;
	int game_over = 1;
	int game_won = 22;
	int f;
	while(game_over != -1) {
		fscanf(in, "%c %d %d", &action, &x, &y);
		if(action == 'r') {
			game_over = reveal_cell(board, rows, columns, x, y);
			if(game_over == 0)
				right_moves++;
		} else if (action == 'f') {
			f = flag_cell(board, rows, columns, x, y);
			if(f == 0) {
				right_moves++;
			}
		}
		counter = 0;
		counter = is_game_won(board, rows, columns, mines, counter);
		if(counter == rows * columns - mines) {
			game_won = 1;
			break;
		}
		
	}
	fclose(in);
	free_board(board, rows, columns);
	printf("Stan koncowy: %d Liczba punktow: %d Liczba poprawnych ruchow; %d\n", game_won, counter, right_moves);

}

