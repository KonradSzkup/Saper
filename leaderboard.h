#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#define MAX_NAME_LENGTH 50
#define MAX_PLAYERS 100

typedef struct {
	char name[MAX_NAME_LENGTH];
	int score;
} Player;

void add_to_leaderboard(int score, char *name, char *file);

void print_leaderboard(char *file);

#endif
