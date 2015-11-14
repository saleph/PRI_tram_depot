#include "../include/trams_array.h"


Tram trams[MAX_ARRAY_SIZE];
int trams_array_size = 0;


void initialize_array()
{
    set_the_tram(&trams[0], 1, 4, "101N", 111, "Wodzirej Mateusz");
    set_the_tram(&trams[1], 2, 12, "23P", 2345, "Wodzirej Wojciech");
    set_the_tram(&trams[2], 3, 3, "001K", 2322, "Sierpien Krzysztof");
    set_the_tram(&trams[3], 4, 5, "TRN1", 7658, "Shopenhauer Artur");
    set_the_tram(&trams[4], 5, 5, "TRN2", 6789, "Siemiow Dimitrij");
    set_the_tram(&trams[5], 6, 5, "IMABOAT", 5454, "Zeglarz Krzysztof");
    set_the_tram(&trams[6], 7, 10, "123N", 3264, "Einstein Albert");
    set_the_tram(&trams[7], 8, 22, "K51W", 3467, "Godna Grazyna");
    set_the_tram(&trams[8], 9, 25, "12", 1678, "Garnek Miroslaw");
    set_the_tram(&trams[9], 10, 97, "18", 5436, "Szyna Maciej");
    set_the_tram(&trams[10], 11, 4, "KWD90", 2643, "Szyszka Adam");
    set_the_tram(&trams[11], 12, 6, "WMKM", 458, "Sosna Mikolaj");
    set_the_tram(&trams[12], 13, 33, "WW123", 1227, "Chrobry Boleslaw");
    set_the_tram(&trams[13], 14, 45, "14", 5656, "Wodzirej Mateusz Skarabeusz");
    set_the_tram(&trams[14], 15, 55, "15", 5677, "Czarna Katarzyna");
    trams_array_size = 15;
}

void print_the_array_by_record_no()
{
    int i;

    if (!trams_array_size) {
        printf("Tablica tramwajow jest pusta!\n");
        return;
    }

    print_labels();
    for (i=0; i<trams_array_size; i++) {
        printf("%2d. ", i+1);
        print_tram_info(trams[i]);
    }
}
