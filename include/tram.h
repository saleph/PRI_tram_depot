#ifndef TRAM_H_INCLUDED
#define TRAM_H_INCLUDED

#include <stdio.h>
#include <string.h>

typedef struct {
    int visible;
    int record_no;
    int line_no;
    char tram_type[16];
    int side_no;
    char motorman_name[256];
} Tram;

void set_the_tram(Tram*, int, int, char[], int, char[]);

void set_visible(Tram*, int);
void set_record_no(Tram*, int);
void set_line_no(Tram*, int);
void set_tram_type(Tram*, char[]);
void set_side_no(Tram*, int);
void set_motorman_name(Tram*, char[]);

void print_tram_info(Tram);
void print_labels();

#endif /* TRAM_H_INCLUDED */
