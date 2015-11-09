#include "depot.h"

void initialize_list();
void start_ui();
void print_menu();
void do_procedure(int);
void adding_new_record();
void editing_record();
void deleting_record();
void cls();


int main()
{
    initialize_list();

    start_ui();

    delete_the_all_list();
    return 0;
}


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

void cls()
{
    printf("\033[2J\033[1;1H");
}

void start_ui()
{
    int choice, idx;
    printf("Witaj w programie do obslugi zajezdni tramwajowej!\n");
    printf("----------------------------------------\n\n");

    for(;;) {
        print_menu();
        scanf("%d", &choice);
        if (!choice) break;

        do_procedure(choice);
    }

    printf("\n=======================\n");
    printf("Wyjscie z programu...\n");
}

void print_menu()
{
    printf("MENU\n");
    printf("   Manipulacja danymi:\n");
    printf("1: Dodaj nowa pozycje.\n");
    printf("2: Edytuj pozycje.\n");
    printf("3: Usun pozycje.\n");
    printf("------------\n");
    printf("   Wyswietlanie danych:\n");
    printf("4: Zgodnie z kolejnoscia wprowadzania.\n");
    printf("5: Rosnaco wedlug numerow linii, a w ramach tego rosnaco wedlug numerow wozow.\n");
    printf("6: Alfabetycznie wedlug typu tramwaju, a w ramach tego wedlug nazwiska i imienia motorniczego.\n");
    printf("------------\n");
    printf("0: WYJSCIE.\n");
    printf("Podaj numer operacji i nacisnij enter: ");
}

void do_procedure(int choice)
{
    switch(choice)
    {
        case 1: {
            cls();
            adding_new_record();
            break;
        }
        case 2: {
            cls();
            editing_record();
            break;
        }
        case 3: {
            cls();
            deleting_record();
            break;
        }
        case 4: {
            cls();
            print_the_list_by_record_no();
            break;
        }
        case 5: {
            cls();
            print_the_list_by_line_no();
            break;
        }
        case 6: {
            cls();
            print_the_list_by_tram_type();
            break;
        }
        default: {
            cls();
            printf("Pozycja menu o takim numerze nie istnieje!\n");
            break;
        }
    }
}

void adding_new_record()
{
    char input_string[256];
    print_the_list_by_record_no();
    printf("Podaj dane nowego rekordu:\n");
    printf("[numer linii: 2 cyfry] [typ tramwaju] [numer boczny: 4 cyfry] [nazwisko motorniczego] [imie motorniczego]\n");

    scanf(" %255[^\n]", &input_string);

    cls();
    add_new_tram_from_input_string(input_string);
}

void editing_record()
{
    int idx;
    char input_string[256];
    print_the_list_by_record_no();
    printf("Podaj numer rekordu do edycji: ");
    scanf("%d", &idx);
    printf("\nPodaj nowe dane rekordu (%d.):\n", idx);
    printf("[numer linii: 2 cyfry] [typ tramwaju] [numer boczny: 4 cyfry] [nazwisko motorniczego] [imie motorniczego]\n");

    scanf(" %255[^\n]", &input_string);

    cls();
    edit_tram_with_index_form_input_string(idx, input_string);
}

void deleting_record()
{
    int idx;
    print_the_list_by_record_no();
    printf("Podaj numer rekordu do usuniecia: ");
    scanf("%d", &idx);

    cls();
    delete_tram_with_index(idx);
}
