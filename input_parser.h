#ifndef INPUT_PARSER_H_INCLUDED
#define INPUT_PARSER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "string_handling.h"

/* wynikiem parsowania stringa jest tablica stringow
o pieciu elementach: numer linii, typ tramwaju,
numer boczny, nazwisko motorniczego, imie motorniczego */
char** parse(char*);
void delete_input_data_array(char**);

#endif /* INPUT_PARSER_H_INCLUDED */
