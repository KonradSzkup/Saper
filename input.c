#include <stdio.h>
#include "input.h"

int get_user_input(int *x, int *y, char *action, int rows, int columns) {
	printf("Podaj akcje\n");
	printf("> ");
	int result = scanf(" %c %d %d", action, x, y);
	if(result != 3 || (*action != 'r' && *action != 'f')) {
		printf("Nie poprawne dane wejsciowe! Sprobuj ponownie \n");
		while(getchar() != '\n');
		return 1;
	}

	if(*x < 0 || *x >= rows || *y < 0 || *y >= columns) {
		printf("Wspolrzedne poza granicami planszy! Sprobuj ponownie \n");
		return 1;
	}

	return 0;
}

int get_game_mode(int *rows, int *columns, int *mines, int *multiplier, char *option) {
	printf("Podaj stopien trudnosci gry, opcje: '1' - latwy 9x9 10min, '2' - sredni 16x16 40min, '3' - trudny 16x30 99min, '4' - wlasny\n");
        printf("> ");
        scanf(" %c", option);
        if(*option == '1') {
                *rows = 9;
                *columns = 9;
                *mines = 10;
                *multiplier = 1;
		return 0;
        } else if(*option == '2') {
                *rows = 16;
                *columns = 16;
                *mines = 40;
                *multiplier = 2;
		return 0;
        } else if(*option == '3') {
                *rows = 16;
                *columns = 30;
                *mines = 99;
                *multiplier = 3;
		return 0;
        } else if(*option == '4') {
                while(option_4(rows, columns, mines) != 0) {
			continue;
		}
		return 0;
        } else {
                printf("Nie udalo sie wczytac poziomu trudnosci lub niepoprawna opcja\n");
                printf("Sprobuj jeszcze raz!\n");
                return 1;
        }
}

int option_4(int *rows, int *columns, int *mines) {
	printf("Podaj wymiray i liczbe min w formacie 'liczba wierszy' 'liczba kolumn' 'liczba min'\n");
        printf("> ");
        scanf(" %d %d %d", rows, columns, mines);
        if(*rows <= 2) {
                printf("Plansza powinna byc przynajmniej 3x3\n");
                return 1;
        }
        if(*columns <= 2) {
                printf("Plansza powinna byc przynajmniej 3x3\n");
                return 1;
        }
	int r = *rows;
	int c = *columns;
        if((r * c) <= *mines) {
                printf("Nie mozesz podac wiecej min niz jest pol na planszy!!\n");
                return 1;
        }
        return 0;
}
