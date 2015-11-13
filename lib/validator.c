#include "../include/validator.h"


int is_line_no_valid(int line_no)
{
    if (line_no >= 0 && line_no <= 99)
        return 1;
    return 0;
}

int is_tram_type_valid(char tram_type[])
{
    unsigned int i;

    for (i=0; i<strlen(tram_type); i++) {
        if (is_digit(tram_type[i]))
            continue;

        if (is_uppercase(tram_type[i]))
            continue;

        if (is_lowercase(tram_type[i])) {
            make_char_uppercase(tram_type[i]);
            continue;
        }

        /* jesli znak nie jest ani liczba, ani litera */
        return 0;
    }

    return 1;
}

int is_digit(char character)
{
    int ascii_code;
    ascii_code = (int)character;

    if (ascii_code >= (int)('0') && ascii_code <= (int)('9'))
        return 1;
    else
        return 0;
}


int is_uppercase(char character)
{
    int ascii_code;
    ascii_code = (int)character;

    if (ascii_code >= (int)('A') && ascii_code <= (int)('Z'))
        return 1;
    else
        return 0;
}

int is_lowercase(char character)
{
    int ascii_code;
    ascii_code = (int)character;

    if (ascii_code >= (int)('a') && ascii_code <= (int)('z'))
        return 1;
    else
        return 0;
}

void make_char_uppercase(char *character)
{
    *character -= (int)('z') - (int)('Z');
}

int is_side_no_valid(int side_no)
{
    if (side_no >= 0 && side_no <= 9999)
        return 1;
    return 0;
}

int is_motorman_name_valid(char name[])
{
    unsigned int i;

    for (i=0; i<strlen(name); i++) {
        if (name[i] == ' ')
            continue;

        /* uczynienie znaku pierwszego / pierwszego po spacji
         * wielka litera */
        if (i == 0 || (i >= 1 && name[i-1] == ' ')) {
            if (is_uppercase(name[i]))
                continue;
            else if (is_lowercase(name[i])) {
                make_char_uppercase(name[i]);
                continue;
            }
        }
        /* dla pozostalych znakow zastosowano zmniejszenie */
        else {
            if (is_lowercase(name[i]))
                continue;
            else if (is_uppercase(name[i])) {
                make_char_lowercase(name[i]);
                continue;
            }
        }
        /* jesli dany znak nie jest litera */
        return 0;
    }

    /* jesli sprawdzenie przebieglo pomyslnie */
    return 1;
}

void make_char_lowercase(char* character)
{
    *character += (int)('a') - (int)('A');
}
