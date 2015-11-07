#ifndef TRAM_H_INCLUDED
#define TRAM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "string_handling.h"

/* TODO: in list's structure - add field RECORD_NO */
typedef struct {
    int line_no;
    char *tram_type;
    int side_no;
    char *motorman_surname;
    char *motorman_name;
} Tram;

Tram* new_tram(int, char*, int, char*, char*);
void print_tram_info(Tram*);
void delete_tram(Tram*);

#endif /* TRAM_H_INCLUDED */
