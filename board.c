#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

void init_board(char **board, int rows, int columns, int mines) {
	
	//Filing board with empty spaces
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			board[i][j] = '.'; //empty space
			board[i][j + columns] = 'n'; // n - not reavealed
		}
	}

	//Placing mines on board
	place_mines(board, rows, columns, mines);

	//Calculating how many adjancent mines
	calculate_adjancent_mines(board, rows, columns);

}

void place_mines(char **board, int rows, int columns, int mines) {
	
	//Placing mines in random places on board
	srand(time(NULL)); 
	int placed_mines = 0;

	while(placed_mines < mines) {
		int x = rand() % rows;
		int y = rand() % columns;
		if(board[x][y] != '*') {
			board[x][y] = '*';
			placed_mines++;
		}
	}
}

void calculate_adjancent_mines(char **board, int rows, int columns) {
	int x_moves[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int y_moves[] = {1, 0, -1, 1, -1, -1, 0, 1};

	for(int x = 0; x < rows; x++) {
		for(int y = 0; y < columns; y++) {
			if(board[x][y] == '*') {
				continue;
			}

			int mines = 0;
			for(int k = 0; k < 8; k++) {
				int nx = x + x_moves[k];
				int ny = y + y_moves[k];
				if(nx >= 0 && nx < rows && ny >= 0 && ny < columns && board[nx][ny] == '*') {
					mines++;
				}
			}
			board[x][y] = mines + '0';
		}
	}
}

void print_board(char **board, int rows, int columns) {
	printf("    ");
	for(int y = 0; y < columns; y++) {
		printf("%2d ", y);
	}
	printf("\n");
	printf("   ");
	for(int y = 0; y < columns; y++) {
		printf("---");
	}
	printf("\n");

	for(int x = 0; x < rows; x++) {
		printf("%2d ", x);
		printf("|");
		for(int y = 0; y < columns; y++) {
			if(board[x][y + columns] == 'f') {
				printf("%2c ", 'f');
			} else if (board[x][y + columns] == 'n') {
				printf("%2c ", '#');
			} else if (board[x][y] == '0') {
				printf("   ");
			} else {
				printf("%2c ", board[x][y]);
			}
		}
		printf("|");
		printf("\n");
	}
	printf("   ");
	for(int y = 0; y < columns; y++) {
                printf("---");
	}
	printf("\n");
}


