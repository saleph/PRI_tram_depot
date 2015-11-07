#include "input_parser.h"


char** parse(char* input_string)
{
    char** fields;
    char* field;
    char* input_data;
    int i, j;

    /* sprawdz, czy input_string jest pusty */
    if (!strlen(input_string)) {
        printf("String wejsciowy jest pusty!\n");
        return NULL;
    }

    /* zaalokuj nowy string (identyczny jak input_string), ale modyfikowalny
    (aby strtok() nie powodowal sigsegv) */
    input_data = new_string(input_string);
    if(!input_data) {
        printf("Blad alokacji pamieci dla tymczasowego stringa z danymi wejsciowymi!\n");
        return NULL;
    }

    /* inicjacja tablicy stringow */
    fields = calloc(5, sizeof(char*));
    if (!fields) {
        printf("Blad alokacji pamieci dla tablicy danych tramwaju!\n");
        free(input_data);
        return NULL;
    }

    /* pierwsza wydzielenie pola z danymi */
    field = strtok(input_data, " ");
    if (!field) {
        printf("Blad alokacji pamieci dla stringa w tablicy danych tramwaju!\n");
        free(fields);
        free(input_data);
        return NULL;
    }
    fields[0] = new_string(field);


    for (i=1; i<5; i++) {
        /* wydziel kolejne pole */
        field = strtok(NULL, " ");

        /* jesli strtok zwrocil NULL */
        if (!field) {
            /* jesli pojawily sie tylko 4 pola, to strtok przy 5 obrocie zwroci juz NULL */
            if (i == 4) printf("Brak imienia/nazwiska motorniczego!\n");
            else printf("Blad alokacji pamieci dla stringa w tablicy danych tramwaju!\n");
            /* czyszczenie juz zaalokowanych stringow */
            for (j=0; j<i; j++) free(fields[i]);
            free(fields);
            free(input_data);
            return NULL;
        }
        fields[i] = new_string(field);
    }

    free(input_data);
    return fields;
}

void delete_input_data_array(char** data_array)
{
    int i;
    for (i=0; i<5; i++) free(data_array[i]);
    free(data_array);
}
