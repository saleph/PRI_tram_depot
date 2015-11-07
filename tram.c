#include "tram.h"

Tram* new_tram(int line_no, char* tram_type, int side_no, char* motorman_surname, char* motorman_name)
{
    Tram* tram;
    char* tram_type_ptr;
    char* motorman_name_ptr;
    char* motorman_surname_ptr;

    tram = malloc(sizeof *tram);
    if (!tram) {
        printf("Blad alokacji pamieci dla struktury \"Tram\"!\n");
        return NULL;
    }

    /* new_string z nagłówka string_handling.h */
    tram_type_ptr = new_string(tram_type);
    if (!tram_type_ptr) {
        printf("Blad alokacji pamieci dla stringa \"typ_tramwaju\"!\n");
        free(tram);
        return NULL;
    }

    motorman_surname_ptr = new_string(motorman_surname);
    if (!motorman_surname_ptr) {
        printf("Blad alokacji pamieci dla stringa \"imie_motorniczego\"!\n");
        free(tram_type_ptr);
        free(tram);
        return NULL;
    }

    motorman_name_ptr = new_string(motorman_name);
    if (!motorman_name_ptr) {
        printf("Blad alokacji pamieci dla stringa \"imie_motorniczego\"!\n");
        free(tram_type_ptr);
        free(motorman_surname_ptr);
        free(tram);
        return NULL;
    }

    tram->line_no = line_no;
    tram->tram_type = tram_type_ptr;
    tram->side_no = side_no;
    tram->motorman_surname = motorman_surname_ptr;
    tram->motorman_name = motorman_name_ptr;

    return tram;
}

void delete_tram(Tram* tram)
{
    free(tram->tram_type);
    free(tram->motorman_name);
    free(tram);
}
