#include "depot.h"


void initialize_list()
{
    add_new_tram_from_input_string("02 ab100 0005 a a");
    add_new_tram_from_input_string("05 cd101 0002 b b");
    add_new_tram_from_input_string("01 efsfs 0001 c d");
    add_new_tram_from_input_string("05 ghafs 0003 d c");
}


int main()
{
    initialize_list();
    print_the_list_by_line_no();
    printf("\n\n");
    print_the_list_by_record_no();
    printf("\n\n");
    print_the_list_by_tram_type();
}
