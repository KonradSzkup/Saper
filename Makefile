saper: board.o memory.o main.o game_logic.o input.o game.o read_from_file.o leaderboard.o
	cc board.o memory.o main.o game_logic.o input.o game.o leaderboard.o read_from_file.o -o saper

board.o: board.c
	cc -c board.c

memory.o: memory.c
	cc -c memory.c

main.o: main.c
	cc -c main.c

game_logic.o: game_logic.c
	cc -c game_logic.c

input.o: input.c
	cc -c input.c

game.o: game.c
	cc -c game.c

read_from_file.o: read_from_file.c
	cc -c read_from_file.c

leaderboard.o: leaderboard.c
	cc -c leaderboard.c
