#ifndef VALIDATOR_H_INCLUDED
#define VALIDATOR_H_INCLUDED

#include "input_parser.h"

int is_input_data_valid(char**);

int is_line_no_valid(char*);
int is_tram_type_valid(char*);
int is_side_no_valid(char*);
int is_motorman_surname_valid(char*);
int is_motorman_name_valid(char*);

int is_first_upper_next_lower(char*);

int is_digit(char);
int is_uppercase(char);
int is_lowercase(char);

void make_first_upper_next_lower(char*);
void make_uppercase(char*);
void make_char_uppercase(char*);
void make_char_lowercase(char*);

#endif /* VALIDATOR_H_INCLUDED */
