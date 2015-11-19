#include "../include/ui.h"


void cls()
{
    printf("\033[2J\033[1;1H");
}

void start_ui()
{
    char temp_str[16];
    int choice;
    printf("Witaj w programie do obslugi zajezdni tramwajowej!\n");
    printf("----------------------------------------\n\n");

    for(;;) {
        print_menu();
        scanf("%s", temp_str);
        while (!is_number(temp_str)) {
            printf("To nie jest liczba!\n");
            printf("Podaj numer operacji i nacisnij enter: ");
            scanf("%s", temp_str);
        }
        choice = atoi(temp_str);

        if (!choice) break;

        do_procedure(choice);
    }

    printf("\n=======================\n");
    printf("Wyjscie z programu...\n");
}

void print_menu()
{
    printf("MENU\n");
    printf("   Modyfikacja:\n");
    printf("1: Dodaj nowy rekord.\n");
    printf("2: Edytuj rekord.\n");
    printf("3: Usun rekord.\n");
    printf("------------\n");
    printf("   Wyswietlanie danych:\n");
    printf("4: Zgodnie z kolejnoscia wprowadzania.\n");
    printf("5: Rosnaco wedlug numerow linii, a w ramach tego rosnaco wedlug numerow bocznych.\n");
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
            print_the_array_by_record_no();
            break;
        }
        case 5: {
            cls();
            print_the_array_by_line_no();
            break;
        }
        case 6: {
            cls();
            print_the_array_by_tram_type();
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
    char temp_str[16];
    int i;
    int line_no;
    char tram_type[16];
    int side_no;
    char motorman_name[256];

    if (trams_array_size >= MAX_ARRAY_SIZE) {
        printf("Tablica jest juz pelna! Nie mozna dodac kolejnych rekordow!\n");
        return;
    }

    print_the_array_by_record_no();

    printf("Podaj dane nowego rekordu (0 by przerwac):\n");

    for(;;) {
        printf("Numer linii (<100): ");
        scanf("%s", temp_str);
        if (!is_number(temp_str)) {
            printf("To nie jest liczba!\n");
            continue;
        }
        else
            line_no = atoi(temp_str);

        if (line_no == 0) {
            cls();
            return;
        }
        if (!is_line_no_valid(line_no)) {
            printf("Nieprawidlowy numer linii!\n");
            continue;
        }
        break;
    }

    for(;;) {
        printf("Typ tramwaju: ");
        scanf("%s", tram_type);
        if (tram_type[0] == '0' && strlen(tram_type) == 1) {
            cls();
            return;
        }
        if (!is_tram_type_valid(tram_type)) {
            printf("Nieprawidlowy typ tramwaju!\n");
            continue;
        }
        break;
    }

    for(;;) {
        printf("Numer boczny (<10000): ");
        scanf("%s", temp_str);
        if (!is_number(temp_str)) {
            printf("To nie jest liczba!\n");
            continue;
        }
        else
            side_no = atoi(temp_str);

        if (side_no == 0) {
            cls();
            return;
        }
        if (!is_side_no_valid(side_no)) {
            printf("Nieprawidlowy numer boczny!\n");
            continue;
        }
        break;
    }

    for(;;) {
        printf("Nazwisko i imie motorniczego: ");
        scanf(" %255[^\n]", motorman_name);
        if (motorman_name[0] == '0' && strlen(motorman_name) == 1) {
            cls();
            return;
        }
        if (!is_motorman_name_valid(motorman_name)) {
            printf("Nieprawidlowa godnosc!\n");
            continue;
        }
        break;
    }

    cls();

    /* szukanie indeksu z nieuzywanym tramwajem */
    for (i=0; i<trams_array_size; i++)
        if (!trams[i].visible) break;

    set_the_tram(&trams[i], i+1, line_no, tram_type, side_no, motorman_name);
    trams_array_size++;
}

void editing_record()
{
    char idx_str[16], choice_str[16];
    int idx, choice;

    print_the_array_by_record_no();
    printf("Podaj numer rekordu do edycji (0 by przerwac): ");
    scanf("%s", idx_str);
    cls();
    if (!is_number(idx_str)) {
        printf("To nie jest liczba!\n");
        return;
    }
    else
        idx = atoi(idx_str);

    if (idx > trams_array_size) {
        printf("Nie ma takiego rekordu!\n");
        return;
    }

    if (!idx) {
        cls();
        return;
    }

    for(;;) {
        print_labels();
        printf("%2d. ", 1);
        print_tram_info(trams[idx-1]);
        printf("-----------\n");
        printf("Co chcesz zmienic?\n");
        printf("1. Numer linii\n");
        printf("2. Typ tramwaju\n");
        printf("3. Numer boczny\n");
        printf("4. Imie i nazwisko\n");
        printf("-----------\n");
        printf("Podaj numer i nacisnij enter (0 aby zakonczyc edycje): ");
        scanf("%s", choice_str);
        while (!is_number(choice_str)) {
            printf("To nie jest liczba!\n");
            printf("Podaj numer i nacisnij enter (0 aby zakonczyc edycje): ");
            scanf("%s", choice_str);
        }
        choice = atoi(choice_str);
        if (!choice) break;
        edit_dialog(choice, idx);

    }
    cls();
}

void edit_dialog(int choice, int idx)
{
    char temp_str[16];
    int line_no;
    char tram_type[16];
    int side_no;
    char motorman_name[256];

    switch(choice)
    {
        case 1: {
            printf("Aktualnie : %2d\n", trams[idx-1].line_no);
            printf("Podaj nowe: ");
            scanf("%s", temp_str);
            cls();
            if (!is_number(temp_str)) {
                printf("To nie jest liczba!\n");
                break;
            }
            else
                line_no = atoi(temp_str);

            if (!is_line_no_valid(line_no)) {
                cls();
                printf("Nieprawidlowy numer linii!\n");
                break;
            }

            cls();
            trams[idx-1].line_no = line_no;
            break;
        }

        case 2: {
            printf("Aktualnie : %s\n", trams[idx-1].tram_type);
            printf("Podaj nowe: ");
            scanf("%s", tram_type);
            if (!is_tram_type_valid(tram_type)) {
                cls();
                printf("Nieprawidlowy typ tramwaju!\n");
                break;
            }

            cls();
            strcpy(trams[idx-1].tram_type, tram_type);
            break;
        }

        case 3: {
            printf("Aktualnie : %04d\n", trams[idx-1].side_no);
            printf("Podaj nowe: ");
            scanf("%s", temp_str);
            cls();
            if (!is_number(temp_str)) {
                printf("To nie jest liczba!\n");
                break;
            }
            else
                side_no = atoi(temp_str);

            if (!is_side_no_valid(side_no)) {
                cls();
                printf("Nieprawidlowy numer boczny!\n");
                break;
            }

            cls();
            trams[idx-1].side_no = side_no;
            break;
        }

        case 4: {
            printf("Aktualnie : %s\n", trams[idx-1].motorman_name);
            printf("Podaj nowe: ");
            scanf(" %255[^\n]", motorman_name);
            if (!is_motorman_name_valid(motorman_name)) {
                cls();
                printf("Nieprawidlowa godnosc!\n");
                break;
            }

            cls();
            strcpy(trams[idx-1].motorman_name, motorman_name);
            break;
        }
    }
}

void deleting_record()
{
    char idx_str[16];
    int idx, i;
    Tram temp_tram;
    print_the_array_by_record_no();
    printf("Podaj numer rekordu do usuniecia (0 by przerwac): ");
    scanf("%s", idx_str);
    cls();
    if (!is_number(idx_str)) {
        printf("To nie jest liczba!\n");
        return;
    }
    else
        idx = atoi(idx_str);

    if (idx > trams_array_size) {
        cls();
        printf("Nie ma takiego rekordu!\n");
        return;
    }

    if (!idx) {
        cls();
        return;
    }

    trams[idx-1].visible = 0;

    /* cofniecie numerow rekordow */
    for (i=idx; i<trams_array_size; i++)
        trams[i].record_no--;

    /* wyrzucenie 'ukrytego' rekordu na koniec
     * aktualnej listy (tuz za rekordami widocznymi */
    for (i=idx; i<trams_array_size; i++) {
        temp_tram = trams[i-1];
        trams[i-1] = trams[i];
        trams[i] = temp_tram;
    }

    trams_array_size--;
    cls();
}
