#ifndef DEPOT_H_INCLUDED
#define DEPOT_H_INCLUDED

#include "trams_list.h"
#include "input_parser.h"
#include "validator.h"

void add_new_tram_from_input_string(char*);
void edit_tram_with_index_form_input_string(int, char*);
void delete_tram_with_index_from_list(int);

#endif /* DEPOT_H_INCLUDED */
