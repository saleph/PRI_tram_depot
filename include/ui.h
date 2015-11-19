#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

#include <stdlib.h>
#include "trams_array.h"

void start_ui();
void print_menu();
void do_procedure(int);
void adding_new_record();
void editing_record();
void edit_dialog(int, int);
void deleting_record();
void cls();

#endif /* UI_H_INCLUDED */
