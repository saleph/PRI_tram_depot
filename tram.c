#include "tram.h"


void set_the_tram(Tram *tram, int record_no, int line_no,
                  char tram_type[], int side_no, char motorman_name[])
{
    tram->visible = 1;
    tram->record_no = record_no;
    tram->line_no = line_no;
    strcpy(tram->tram_type, tram_type);
    tram->side_no = side_no;
    strcpy(tram->motorman_name, motorman_name);
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
