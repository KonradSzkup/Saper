#include <stdio.h>
#include <stdlib.h>
#include "game_logic.h"

int flag_cell(char **board, int rows, int columns, int x, int y) {
	if(board[x][y + columns] == 'f') {
		board[x][y + columns] = 'n';
		return 0;
	} else if (board[x][y + columns] == 'n') {
		board[x][y + columns] = 'f';
		return 0;
	} else if (board[x][y + columns]  == 'r') {
		return -1; //someone tried to flag revealed cell
	}
	return -2; //failed
}
int reveal_cell(char **board, int rows, int columns,  int x, int y) {
	int x_moves[] = { -1, -1, -1, 0, 0, 1, 1, 1};
	int y_moves[] = { 1, 0, -1, 1, -1, 1, 0, -1};

	if(board[x][y + columns] == 'f' || board[x][y + columns] =='r') {
		return 1; // cell if flaged or already revealed 
	} else if (board[x][y] == '*') {
		return -1; //game is lost
	}

	if(board[x][y] == '0') {
		board[x][y + columns] = 'r';
		for(int i = 0; i < 8; i++) {
			int nx = x + x_moves[i];
			int ny = y + y_moves[i];
			if(nx >= 0 && nx < rows && ny >= 0 && ny < columns) {
				if(board[nx][ny + columns] == 'n') {
					reveal_cell(board, rows, columns, nx, ny);
				}
			}	
		}
	} else if (board[x][y] >= '1' && board[x][y] <= '8') {
		board[x][y + columns] = 'r';
		return 0;
	}
	return 0;
}

