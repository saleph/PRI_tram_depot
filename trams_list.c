#include "trams_list.h"


struct ListNode* root = NULL;
int list_size = 0;

void append_tram(int line_no, char* tram_type, int side_no, char* motorman_surname, char* motorman_name)
{
    struct ListNode* curr_node;
    struct ListNode* new_node;
    new_node = malloc(sizeof(struct ListNode));
    if (!new_node) {
        printf("Blad alokacji pamieci dla nowego elementu listy!");
        return;
    }

    if (!root) {
        new_node->record_no = 1;
        list_size = 1;
        new_node->next = NULL;
        new_node->prev = NULL;
        new_node->tram = new_tram(line_no, tram_type, side_no, motorman_surname, motorman_name);
        root = new_node;
        return;
    }

    for (curr_node=root; curr_node->next; curr_node=curr_node->next);
    /* teraz w curr_node mamy ostatni element listy */

    if (curr_node->record_no >= 18) {
        printf("Przepelnienie: lista zawiera juz 17 elementow!\n");
        free(new_node);
        return;
    }

    new_node->record_no = curr_node->record_no + 1;
    list_size++;
    new_node->next = NULL;
    new_node->prev = curr_node;
    curr_node->next = new_node;
    new_node->tram = new_tram(line_no, tram_type, side_no, motorman_surname, motorman_name);
}

void edit_tram_with_index(int idx, int line_no, char* tram_type, int side_no, char* motorman_surname, char* motorman_name)
{
    struct ListNode* curr_node;

    if (!root) {
        printf("Lista jest pusta!\n");
        return;
    }

    for (curr_node=root; (curr_node->record_no==idx || curr_node==NULL); curr_node=curr_node->next);

    if (!curr_node) {
        printf("Nie ma takiego elementu!\n");
        return;
    }

    edit_tram(curr_node->tram, line_no, tram_type, side_no, motorman_surname, motorman_name);
}

void delete_tram_with_index(int idx)
{
    struct ListNode* curr_node;

    if (!root) {
        printf("Lista jest pusta!\n");
        return;
    }

    curr_node = root;
    while (curr_node) {
        if (curr_node->record_no == idx)
            break;
        curr_node = curr_node->next;
    }

    if (!curr_node) {
        printf("Nie ma takiego elementu!\n");
        return;
    }

    /* cofniecie indeksow rekordow za usuwanym elementem */
    /* wykonuje jedna zbedna dekrementacje (elementu do usuniecia) */
    /* ale nie wymaga obslugi 1-elementowej listy */
    move_back_records_no_from(curr_node);

    /* jesli curr_node jest rootem, nie jest wymagana ani dozwolona zadna podmiana wskaznikow */
    if (list_size > 1) {
        if (curr_node->next == NULL) {
            /* jesli ogon */
            curr_node->prev->next = NULL;
        }
        else if (curr_node->prev == NULL) {
            /* jesli glowa */
            curr_node->next->prev = NULL;
            root = curr_node->next;
        }
        else {
            curr_node->prev->next = curr_node->next;
            curr_node->next->prev = curr_node->prev;
        }
    }

    list_size--;
    delete_tram(curr_node->tram);
    curr_node->next = curr_node->prev = NULL;
    free(curr_node);

    /* jesli juz cala lista zostala usunieta */
    if (!list_size)
        root = NULL;
}

void move_back_records_no_from(struct ListNode* node)
{
    struct ListNode* curr_element;
    for(curr_element=node; curr_element; curr_element=curr_element->next)
        curr_element->record_no--;
}

void print_the_list_by_record_no()
{
    struct ListNode* curr_node;
    if (!root) {
        printf("Lista jest pusta!\n");
        return;
    }

    for (curr_node=root; curr_node; curr_node=curr_node->next) {
        printf("%d. ", curr_node->record_no);
        print_tram_info(curr_node->tram);
    }
}

void print_the_list_by_line_no()
{
    int i;
    struct ListNode** nodes_array;

    if (!root) {
        printf("Lista jest pusta!\n");
        return;
    }

    nodes_array = create_nodes_array();
    if (!nodes_array)
        return;

    sort_by_line_no(nodes_array);

    printf("Rosnaco wzgledem numeru linii:\n");
    for (i=0; i<list_size; i++) {
        printf("%d. ", nodes_array[i]->record_no);
        print_tram_info(nodes_array[i]->tram);
    }

    delete_nodes_array(nodes_array);
}

struct ListNode** create_nodes_array()
{
    /* alokacja tablicy wskaznikow do elementow listy */
    int i;
    struct ListNode* curr_node;
    struct ListNode** nodes_array;
    nodes_array = calloc(list_size, sizeof(struct ListNode*));
    if (!nodes_array) {
        printf("Blad alokacji tymczasowej tablicy uzywanej do sortowania!\n");
        return NULL;
    }

    /* podpiecie wskaznikow wezlow do elementow tablicy */
    for (i=0, curr_node=root; i<list_size && curr_node; i++, curr_node=curr_node->next)
        nodes_array[i] = curr_node;

    return nodes_array;
}

void delete_nodes_array(struct ListNode** nodes_array)
{
    /* nie chcemy czyscic konkretnych wezlow, bo to zniszczylo by dane */
    free(nodes_array);
}

void sort_by_line_no(struct ListNode** nodes_array)
{
    int i, n;
    struct ListNode* temp_node;
    n = list_size;

    do {
        for (i=0; i<n-1; i++) {
            if (nodes_array[i]->tram->line_no > nodes_array[i+1]->tram->line_no)
                swap_nodes(&nodes_array[i], &nodes_array[i+1]);

            if (nodes_array[i]->tram->line_no == nodes_array[i+1]->tram->line_no)
                if(nodes_array[i]->tram->side_no > nodes_array[i+1]->tram->side_no)
                    swap_nodes(&nodes_array[i], &nodes_array[i+1]);
        }
        n--;
    } while (n > 1);
}

void swap_nodes(struct ListNode** first_node, struct ListNode** second_node)
{
    struct ListNode* temp_node;
    temp_node = *first_node;
    *first_node = *second_node;
    *second_node = temp_node;
}

void print_the_list_by_tram_type()
{
    int i;
    struct ListNode** nodes_array;

    if (!root) {
        printf("Lista jest pusta!\n");
        return;
    }

    nodes_array = create_nodes_array();
    if (!nodes_array)
        return;

    sort_by_tram_type(nodes_array);

    printf("Alfabetycznie wzgledem typu tramwaju:\n");
    for (i=0; i<list_size; i++) {
        printf("%d. ", nodes_array[i]->record_no);
        print_tram_info(nodes_array[i]->tram);
    }

    delete_nodes_array(nodes_array);
}

void sort_by_tram_type(struct ListNode** nodes_array)
{
    int i, n, ret_value;
    struct ListNode* temp_node;
    n = list_size;

    do {
        for (i=0; i<n-1; i++) {
            /* porownaj typ tramwaju */
            ret_value = strcmp(nodes_array[i]->tram->tram_type, nodes_array[i+1]->tram->tram_type);
            if (ret_value > 0)
                swap_nodes(&nodes_array[i], &nodes_array[i+1]);

            if (ret_value == 0) {
                /* jesli takie same, porownaj nazwiska */
                ret_value = strcmp(nodes_array[i]->tram->motorman_surname, nodes_array[i+1]->tram->motorman_surname);
                if(ret_value > 0)
                    swap_nodes(&nodes_array[i], &nodes_array[i+1]);

                if (ret_value == 0) {
                    /* jesli takie same, porownaj imiona */
                    ret_value = strcmp(nodes_array[i]->tram->motorman_name, nodes_array[i+1]->tram->motorman_name);
                    if(ret_value > 0)
                        swap_nodes(&nodes_array[i], &nodes_array[i+1]);
                }
            }
        }
        n--;
    } while (n > 1);
}

void delete_the_all_list()
{
    int i, n;
    n = list_size;
    for(i=0; i<n; i++)
        delete_tram_with_index(1);
}
