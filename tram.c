#include <stdlib.h>
#include "tram.h"

Tram* new_tram(int line_no, char* tram_type, int side_no, char* motorman_name)
{
    Tram* tram;
    char* tram_type_ptr;
    char* motorman_name_ptr;

    tram = malloc(sizeof(struct Tram))
    if (!tram) {
        printf("Blad alokacji pamieci dla struktury \"Tram\"!\n");
        free(tram);
        return NULL;
    }

    tram_type_ptr = new_string(tram_type);
    if (!tram_type_ptr) {
        printf("Blad alokacji pamieci dla stringa \"typ_tramwaju\"!\n");
        free(tram);
        return NULL;
    }

    motorman_name_ptr = new_string(motorman_name);
    if (!motorman_name_ptr) {
        printf("Blad alokacji pamieci dla stringa \"imie_motorniczego\"!\n");
        free(tram);
        return NULL;
    }

    tram->line_no = line_no;
    tram->tram_type = tram_type_ptr;
    tram->side_no = side_no;
    tram->motorman_name = motorman_name_ptr;

    return tram;
}

char* new_string(char* my_string)
{
    char* my_string_ptr;

    my_string_ptr = malloc(sizeof my_string);
    if (!my_string_ptr)
        return NULL;

    *my_string_ptr = my_string;
    return my_string_ptr;
}
