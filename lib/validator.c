#include "../include/validator.h"


int is_line_no_valid(int line_no)
{
    return (line_no >= 0 && line_no <= 99) ? 1 : 0;
}

int is_tram_type_valid(char tram_type[])
{
    unsigned int i;

    for (i=0; i<strlen(tram_type); i++) {
        /* dla cyfr i wielkich liter nic nie trzeba robic */
        if (isdigit(tram_type[i]) || isupper(tram_type[i]))
            continue;

        if (islower(tram_type[i])) {
            tram_type[i] = toupper(tram_type[i]);
            continue;
        }

        /* jesli znak nie jest ani liczba, ani litera */
        return 0;
    }

    return 1;
}

int is_side_no_valid(int side_no)
{
    return (side_no >= 0 && side_no <= 9999) ? 1 : 0;
}

int is_motorman_name_valid(char name[])
{
    unsigned int i;

    for (i=0; i<strlen(name); i++) {
        if (isspace(name[i]))
            continue;

        /* uczynienie znaku pierwszego / pierwszego po spacji
         * wielka litera */
        if (i == 0 || (i >= 1 && isspace(name[i-1]))) {
            if (isupper(name[i]))
                continue;

            if (islower(name[i])) {
                name[i] = toupper(name[i]);
                continue;
            }
        }
        /* dla pozostalych znakow zastosowano zmniejszenie */
        else {
            if (islower(name[i]))
                continue;

            if (isupper(name[i])) {
                name[i] = tolower(name[i]);
                continue;
            }
        }

        /* jesli dany znak nie jest litera */
        return 0;
    }

    /* jesli sprawdzenie i zamiany przebiegly pomyslnie */
    return 1;
}

int is_number(char a_string[])
{
    unsigned int i;
    for (i=0; i<strlen(a_string); i++)
        if (!isdigit(a_string[i]))
            return 0;

    return 1;
}
