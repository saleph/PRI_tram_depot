#include "depot.h"


void add_new_tram_from_input_string(char* input_string)
{
    char** input_data;

    input_data = parse(input_string);
    /* jesli parsowanie sie nie powiodlo, zwroci bledy i NULL */
    if(!input_data)
        return;

    if (!is_input_data_valid(input_data)) {
        delete_input_data_array(input_data);
        return;
    }

    append_tram(to_number(input_data[0]), input_data[1], to_number(input_data[2]), input_data[3], input_data[4]);
    delete_input_data_array(input_data);
}

void edit_tram_with_index_form_input_string(int idx, char* input_string)
{
    char** input_data;

    input_data = parse(input_string);
    /* jesli parsowanie sie nie powiodlo, zwroci bledy i NULL */
    if(!input_data)
        return;

    if (!is_input_data_valid(input_data)) {
        delete_input_data_array(input_data);
        return;
    }

    edit_tram_with_index(idx, to_number(input_data[0]), input_data[1], to_number(input_data[2]), input_data[3], input_data[4]);
    delete_input_data_array(input_data);
}

void delete_tram_with_index_from_list(int idx)
{
    delete_tram_with_index(idx);
}
