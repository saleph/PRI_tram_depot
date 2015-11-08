#include "depot.h"


void initialize_list()
{
    add_new_tram_from_input_string("02 ab100 0005 a a");
    add_new_tram_from_input_string("05 cd101 0002 b b");
    add_new_tram_from_input_string("01 afsfs 0001 c d");
    add_new_tram_from_input_string("05 ghafs 0007 d c");
    add_new_tram_from_input_string("05 ghafs 0002 d ca");
    add_new_tram_from_input_string("05 zhafa 0004 d c");
    add_new_tram_from_input_string("05 ghafs 0001 d ab");
    add_new_tram_from_input_string("05 1hafs 0005 c x");
    add_new_tram_from_input_string("05 chafs 0005 d f");
}


int main()
{
    initialize_list();
    print_the_list_by_record_no();
    printf("\n\nPo edycji:\n");

    edit_tram_with_index_form_input_string(5, "00 lolo1 9999 x x");
    print_the_list_by_record_no();

    printf("\n\n");
    delete_the_all_list();
    print_the_list_by_record_no();
}
