#ifndef TRAMS_ARRAY_H_INCLUDED
#define TRAMS_ARRAY_H_INCLUDED

#include "tram.h"
#include "validator.h"

#define MAX_ARRAY_SIZE 17


extern Tram trams[MAX_ARRAY_SIZE];
extern int trams_array_size;

void initialize_array();

void print_the_array_by_record_no();
void print_the_array_by_line_no();
void print_the_array_by_tram_type();

#endif /* TRAMS_ARRAY_H_INCLUDED */
