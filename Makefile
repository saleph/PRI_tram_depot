compile: *.c
	gcc -o tram_depoter *.c -ansi -pedantic -Wall
run: *.c
	./tram_depoter
