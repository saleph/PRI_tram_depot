#include "validator.h"


int is_input_data_valid(char** input_data)
{
    /* funkcja zwraca 1 jesli wszyskie argumenty sa dobre
    0, jesli ktorys jest bledny */
    int validation_status;

    /* walidacja numeru linii */
    validation_status = is_line_no_valid(input_data[0]);
    if(!validation_status) {
        printf("Numer linii jest nieprawidlowy!\n");
        return 0;
    }

    /* walidacja typu tramwaju */
    validation_status = is_tram_type_valid(input_data[1]);
    if(validation_status == 0) {
        printf("Numer linii jest nieprawidlowy!\n");
        return 0;
    } else if (validation_status == 2)
        make_string_uppercase(input_data[1]);

    /* walidacja numeru bocznego tramwaju */
    validation_status = is_side_no_valid(input_data[2]);
    if(!validation_status) {
        printf("Numer boczny jest nieprawidlowy!\n");
        return 0;
    }

    /* walidacja nazwiska */
    validation_status = is_motorman_surname_valid(input_data[3]);
    if(validation_status == 0) {
        printf("Nazwisko motorniczego jest nieprawidlowe!\n");
        return 0;
    } else if (validation_status == 2)
        make_first_upper_next_lower(input_data[3]);

    /* walidacja imienia */
    validation_status = is_motorman_name_valid(input_data[4]);
    if(validation_status == 0) {
        printf("Imie motorniczego jest nieprawidlowe!\n");
        return 0;
    } else if (validation_status == 2)
        make_first_upper_next_lower(input_data[4]);

    /* jesli wszystko poszlo dobrze */
    return 1;
}

int is_line_no_valid(char* line_no)
{
    int i;
    if(strlen(line_no) != 2) {
        printf("Numer linii musi skladac sie z dwoch cyfr!\n");
        return 0;
    }

    for (i=0; i<2; i++) {
        if (!is_digit(line_no[i])) {
            printf("Numer linii musi skladac sie tylko z cyfr!\n");
            return 0;
        }
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

int is_tram_type_valid(char* tram_type)
{
    unsigned int i;
    int has_to_be_uppercased;
    has_to_be_uppercased = 0;

    for (i=0; i<strlen(tram_type); i++) {
        if (is_digit(tram_type[i]))
            continue;

        if (is_uppercase(tram_type[i]))
            continue;
        else if (is_lowercase(tram_type[i])) {
            has_to_be_uppercased = 1;
            continue;
        }

        /* jesli znak nie jest ani liczba, ani litera */
        return 0;
    }

    if(!has_to_be_uppercased)
        return 1;
    else
        return 2;
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

void make_string_uppercase(char* a_string)
{
    unsigned int i;
    for (i=0; i<strlen(a_string); i++)
        if (is_lowercase(a_string[i]))
            make_char_uppercase(&a_string[i]);
}

void make_char_uppercase(char *character)
{
    *character -= (int)('z') - (int)('a') + (int)('a') - (int)('Z');
}

int is_side_no_valid(char* side_no)
{
    int i;

    if(strlen(side_no) != 4) {
        printf("Numer boczny musi skladac sie z czterech cyfr!\n");
        return 0;
    }

    for (i=0; i<4; i++) {
        if (!is_digit(side_no[i])) {
            printf("Numer boczny musi skladac sie tylko z cyfr!\n");
            return 0;
        }
    }
    return 1;
}

int is_motorman_surname_valid(char* surname)
{
    int validation_value;
    validation_value = is_first_upper_next_lower(surname);
    return validation_value;
}

int is_first_upper_next_lower(char* a_string)
{
    unsigned int i;
    int has_to_be_upper_or_lower_cased;
    has_to_be_upper_or_lower_cased = 0;

    for (i=0; i<strlen(a_string); i++) {
        if (i == 0) {
            if (is_uppercase(a_string[i]))
                continue;
            else if (is_lowercase(a_string[i])) {
                has_to_be_upper_or_lower_cased = 1;
                continue;
            }
        } else {
            if (is_lowercase(a_string[i]))
                continue;
            else if (is_uppercase(a_string[i])) {
                has_to_be_upper_or_lower_cased = 1;
                continue;
            }
        }
        return 0;
    }

    if (!has_to_be_upper_or_lower_cased)
        return 1;
    else
        return 2;
}

void make_first_upper_next_lower(char* a_string)
{
    unsigned int i;

    if (is_lowercase(a_string[0]))
        make_char_uppercase(a_string[0]);

    for (i=1; i<strlen(a_string); i++)
        if (is_uppercase(a_string[i]))
            make_char_lowercase(a_string[i]);
}

void make_char_lowercase(char* character)
{
    *character += (int)('Z') - (int)('A') + (int)('a') - (int)('Z');
}

int is_motorman_name_valid(char* name)
{
    int validation_value;
    validation_value = is_first_upper_next_lower(name);
    return validation_value;
}
