#include "trams_array.h"


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
    set_the_tram(&trams[6], 7, 10, "IMABOAT", 3264, "Zeglarz Krzysztof Junior");
    set_the_tram(&trams[7], 8, 22, "K51W", 3467, "Godna Grazyna");
    set_the_tram(&trams[8], 9, 25, "12", 1678, "Garnek Miroslaw");
    set_the_tram(&trams[9], 10, 97, "18", 5436, "Szyna Maciej");
    set_the_tram(&trams[10], 11, 4, "KWD90", 2643, "Szyszka Adam");
    set_the_tram(&trams[11], 12, 6, "WMKM", 458, "Sosna Mikolaj");
    set_the_tram(&trams[12], 13, 33, "WW123", 1227, "Chrobry Boleslaw");
    set_the_tram(&trams[13], 14, 45, "14", 5656, "Wodzirej Mateusz Skarabeusz");
    set_the_tram(&trams[14], 15, 55, "15", 5677, "Einstein Albert");
    trams_array_size = 15;
}

void print_the_array_by_record_no()
{
    int i;

    if (!trams_array_size) {
        printf("Tablica tramwajow jest pusta!\n");
        return;
    }

    printf("Rosnaco wzgledem kolejnosci wprowadzania:\n");
    print_labels();
    for (i=0; i<trams_array_size; i++) {
        printf("%2d. ", i+1);
        print_tram_info(trams[i]);
    }

    printf("------------\n");
}

void print_the_array_by_line_no()
{
    int *indexes, i;

    if (!trams_array_size) {
        printf("Tablica tramwajow jest pusta!\n");
        return;
    }

    indexes = get_sorted_by_line_no();

    printf("Rosnaco wzgledem numeru linii:\n");
    print_labels();
    for (i=0; i<trams_array_size; i++) {
        printf("%2d. ", i+1);
        print_tram_info(trams[indexes[i]]);
    }

    printf("------------\n");
}

int* get_sorted_by_line_no()
{
    static int indexes[MAX_ARRAY_SIZE];
    int i, n;
    n = trams_array_size;

    for (i=0; i<n; i++)
        indexes[i] = i;

    do {
        for (i=0; i<n-1; i++) {
            /* porownaj numery linii */
            if (trams[indexes[i]].line_no > trams[indexes[i+1]].line_no)
                swap_elements(&indexes[i], &indexes[i+1]);

            /* jesli numery linii rowne, porownaj numery boczne */
            if (trams[indexes[i]].line_no == trams[indexes[i+1]].line_no)
                if(trams[indexes[i]].side_no > trams[indexes[i+1]].side_no)
                    swap_elements(&indexes[i], &indexes[i+1]);
        }
        n--;
    } while (n > 1);

    return indexes;
}

void swap_elements(int *first, int *second)
{
    int temp;

    temp = *first;
    *first = *second;
    *second = temp;
}

void print_the_array_by_tram_type()
{
    int *indexes, i;

    if (!trams_array_size) {
        printf("Tablica tramwajow jest pusta!\n");
        return;
    }

    indexes = get_sorted_by_tram_type();

    printf("Alfabetycznie wzgledem typu tramwaju:\n");
    print_labels();
    for (i=0; i<trams_array_size; i++) {
        printf("%2d. ", i+1);
        print_tram_info(trams[indexes[i]]);
    }

    printf("------------\n");
}

int* get_sorted_by_tram_type()
{
    static int indexes[MAX_ARRAY_SIZE];
    int i, n, ret_value;
    n = trams_array_size;

    for (i=0; i<n; i++)
        indexes[i] = i;

    do {
        for (i=0; i<n-1; i++) {
            /* porownaj typ tramwaju */
            ret_value = strcmp(trams[indexes[i]].tram_type, trams[indexes[i+1]].tram_type);
            if (ret_value > 0)
                swap_elements(&indexes[i], &indexes[i+1]);

            if (ret_value == 0) {
                /* jesli takie same, porownaj imiona */
                ret_value = strcmp(trams[indexes[i]].motorman_name, trams[indexes[i+1]].motorman_name);
                if(ret_value > 0)
                    swap_elements(&indexes[i], &indexes[i+1]);
            }
        }
        n--;
    } while (n > 1);

    return indexes;
}
