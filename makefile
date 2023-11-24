build:
	@gcc -o tic-tac-toe *.c

run:
	@./tic-tac-toe

clear:
	clear

start: clear build run