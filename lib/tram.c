#include "../include/tram.h"


void set_the_tram(Tram *tram, int record_no, int line_no,
                  char tram_type[], int side_no, char motorman_name[])
{
    set_visible(tram, 1);

    set_record_no(tram, record_no);
    set_line_no(tram, line_no);
    set_tram_type(tram, tram_type);
    set_side_no(tram, side_no);
    set_motorman_name(tram, motorman_name);
}

void set_visible(Tram *tram, int visible)
{
    (*tram).visible = visible;
}

void set_record_no(Tram *tram, int record_no)
{
    (*tram).record_no = record_no;
}

void set_line_no(Tram *tram, int line_no)
{
    (*tram).line_no = line_no;
}

void set_tram_type(Tram *tram, char tram_type[])
{
    int i;
    for (i=0; i<strlen(tram_type); i++)
        (*tram).tram_type[i] = tram_type[i];
    (*tram).tram_type[strlen(tram_type)] = '\0';
}

void set_side_no(Tram *tram, int side_no)
{
    (*tram).side_no = side_no;
}

void set_motorman_name(Tram *tram, char motorman_name[])
{
    int i;
    for (i=0; i<strlen(motorman_name); i++)
        (*tram).motorman_name[i] = motorman_name[i];
    (*tram).motorman_name[strlen(motorman_name)] = '\0';
}

void print_tram_info(Tram tram)
{
    printf(" %2d: |       %2d | %7s |      %04d | %s\n", tram.record_no, tram.line_no,
           tram.tram_type, tram.side_no, tram.motorman_name);
}

void print_labels()
{
    printf("  Rekord | Nr linii |     Typ | Nr boczny | Nazwisko i imie motorniczego\n");
}
