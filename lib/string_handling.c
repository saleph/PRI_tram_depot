#include "../include/string_handling.h"


char* new_string(char* my_string)
{
    char* my_new_string;

    my_new_string = calloc(strlen(my_string) + 1, sizeof (char));
    if (!my_new_string)
        return NULL;

    strcpy(my_new_string, my_string);

    return my_new_string;
}
