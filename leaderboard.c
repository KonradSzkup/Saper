#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leaderboard.h"

int compare_scores(const void *a, const void *b) {
	Player *playerA = (Player *)a;
	Player *playerB = (Player *)b;
	return playerB->score - playerA->score;
}

void add_to_leaderboard(int score, char *name, char *file) {
	Player players[MAX_PLAYERS];
	int count = 0;

	FILE *in = fopen(file, "r");
	if(in != NULL) {
		while(fscanf(in, "%49s %d", players[count].name, &players[count].score) == 2) {
			count++;
		}
		fclose(in);
	}

	strncpy(players[count].name, name, MAX_NAME_LENGTH -1);
	players[count].name[MAX_NAME_LENGTH -1] = '\0';
	players[count].score = score;
	count++;

	qsort(players, count, sizeof(Player), compare_scores);

	FILE *out = fopen(file, "w");
	if(out != NULL) {
		for(int i = 0; i < count && i < MAX_PLAYERS; i++) {
			fprintf(out, "%s %d\n", players[i].name, players[i]. score);
		}
	fclose(out);	
	}
}

void print_leaderboard(char *file) {
	Player players[MAX_PLAYERS];
	int count = 0;

	FILE *in = fopen(file, "r");
	if(in != NULL) {
		while(fscanf(in, "%49s %d", players[count].name, &players[count].score) == 2) {
                        count++;
                }
                fclose(in);
        }

	printf("Top 5 graczy:\n");
	for(int i = 0; i < count && i < 5; i++) {
		printf("%d. %s - %d\n", i + 1, players[i].name, players[i].score);	
	}

}
