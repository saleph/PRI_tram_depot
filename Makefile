trammake: main.c lib/*.c
	gcc -o tram_depoter main.c lib/*.c -ansi -pedantic -Wall && ./tram_depoter
compile: main.c lib/*.c
	gcc -o tram_depoter main.c lib/*.c -ansi -pedantic -Wall
