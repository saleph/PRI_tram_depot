#ifndef INPUT_PARSER_H_INCLUDED
#define INPUT_PARSER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "string_handling.h"
#define DATAFIELDS 5

/* wynikiem parsowania stringa jest tablica stringow
o pieciu elementach: numer linii, typ tramwaju,
numer boczny, nazwisko motorniczego, imie motorniczego */
char** parse(char*);
void delete_input_data_array(char**);

int to_number(char*);
int to_digit(char);

#endif /* INPUT_PARSER_H_INCLUDED */
