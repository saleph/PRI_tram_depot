#ifndef VALIDATOR_H_INCLUDED
#define VALIDATOR_H_INCLUDED

#include <string.h>

int is_line_no_valid(int);
int is_tram_type_valid(char[]);
int is_side_no_valid(int);
int is_motorman_name_valid(char[]);

int is_number(char[]);
int is_digit(char);
int is_uppercase(char);
int is_lowercase(char);

void make_char_uppercase(char*);
void make_char_lowercase(char*);
int to_number(char[]);
int to_digit(char);

#endif /* VALIDATOR_H_INCLUDED */
