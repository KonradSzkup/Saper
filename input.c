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


