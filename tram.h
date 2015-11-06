#ifndef TRAM_H_INCLUDED
#define TRAM_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

/* TODO: in list's structure - add field RECORD_NO */
typedef struct {
    int line_no;
    char *tram_type;
    int side_no;
    char *motorman_name;
} Tram;

Tram* new_tram(int, char*, int, char*);
char* new_string(char*);
void  delete_tram(Tram*);

#endif /* TRAM_H_INCLUDED */
