#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "memory.h"
#include "board.h"
#include "game_logic.h"
#include "game.h"
#include "input.h"

int game() {
	int rows;
	int columns;
	int mines;
	int multiplier;
	char option;
	printf("Podaj stopien trudnosci gry, opcje: '1' - latwy 9x9 10min, '2' - sredni 16x16 40min, '3' - trudny 16x30 99min, '4' - wlasny\n");
	printf("> ");
	scanf(" %c", &option);
	if(option == '1') {
		rows = 9;
        	columns = 9;
        	mines = 10;
		multiplier = 1;
	} else if(option == '2') {
		rows = 16;
        	columns = 16;
        	mines = 40;
		multiplier = 2;
	} else if(option == '3') {
		rows = 16;
        	columns = 30;
        	mines = 99;
		multiplier = 3;
	} else if(option == '4') {
		printf("Podaj wymiray i liczbe min w formacie 'liczba wierszy' 'liczba kolumn' 'liczba min'\n");
		printf("> ");
		scanf(" %d %d %d", &rows, &columns, &mines);
	} else {
		printf("Nie udalo sie wczytac poziomu trudnosci lub niepoprawna opcja\n");
		printf("Sprobuj jeszcze raz!\n");
		return -1;
	}

	char **board = allocate_board(rows, columns);

	int game_over = 1;
	int game_won = 0;

	int i = 0;
	int counter = 0;

	while(game_over != -1) {
		system("clear");
		if(option != '4') {
			printf("Aktualny wynik to: %d\n", counter * multiplier);
		}

		if(i == 0) {
			print_first_board(rows, columns);
		} else {
			print_board(board, rows, columns, 'n');
		}
		int x, y, f;
		char action;

		if(get_user_input(&x, &y, &action, rows, columns) == 1) {
			continue;
		}

		if(i == 0) {
			init_board(board, rows, columns, mines, x, y);
			i++;
		}

		if(action == 'r') {
			game_over = reveal_cell(board, rows, columns, x, y);
		} else if (action == 'f') {
			f = flag_cell(board, rows, columns, x, y);
			if(f == 1)
				printf("Nie mozesz oflagowac odkrytej komorki");
		}
		counter = 0;
		counter = is_game_won(board, rows, columns, mines, counter);
		
		if(counter == rows * columns - mines) {
			system("clear");
			printf("Wygrales\n");
			printf("Twoj wynik to %d\n", counter*multiplier);
			printf("Oto odkryta planasza\n");
			print_board(board, rows, columns, 'r');
			break;
		}

		if(game_over == -1) {
			system("clear");
			printf("Przegrales\n");
			printf("Twoj wynik to %d\n", counter*multiplier);
			printf("Odkryta plansza\n");
			print_board(board, rows, columns, 'r');
		}
	}

	free_board(board, rows, columns);
}



