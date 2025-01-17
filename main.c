#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "game.h"
#include "read_from_file.h"

int main(int argc, char **argv) {
	int opt;
	char *filename = NULL;
	int use_file = 0;
		
	while ((opt = getopt(argc, argv, "f:")) != -1) {
		switch (opt) {
			case 'f':
				filename = optarg;
				use_file = 1;
				break;
			default:
			printf("Uzycie: %s [-f nazwa_pliku]\n", argv[0]);
			return EXIT_FAILURE;
		}
	}

	if(use_file) {
		read_from_file(filename);
	} else { 
		game();
	}

	return EXIT_SUCCESS;
}
