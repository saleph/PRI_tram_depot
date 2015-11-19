#ifndef VALIDATOR_H_INCLUDED
#define VALIDATOR_H_INCLUDED

#include <string.h>
#include <ctype.h>

int is_line_no_valid(int);
int is_tram_type_valid(char[]);
int is_side_no_valid(int);
int is_motorman_name_valid(char[]);

int is_number(char[]);

#endif /* VALIDATOR_H_INCLUDED */
