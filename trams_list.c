#include "trams_list.h"


void append_tram(Tram* a_new_tram)
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
        new_node->next = NULL;
        new_node->prev = NULL;
        new_node->tram = a_new_tram;
        root = new_node;
        return;
    }

    for (curr_node=root; curr_node->next; curr_node=curr_node->next);
    /* teraz w curr_node mamy ostatni element listy */


    new_node->record_no = curr_node->record_no + 1;
    new_node->next = NULL;
    new_node->prev = curr_node;
    new_node->tram = a_new_tram;
}

void delete_tram_with_index(int idx)
{
    struct ListNode* curr_node;

    if (!root) {
        printf("Nie mozna usunac elementu z pustej listy!\n");
        return;
    }

    for (curr_node=root; (curr_node->record_no==idx || curr_node==NULL); curr_node=curr_node->next);

    if (!curr_node) {
        printf("Nie ma takiego indeksu!\n");
        return;
    }

    /* cofniecie indeksow rekordow za usuwanym elementem */
    /* wykonuje jedna zbedna dekrementacje (elementu do usuniecia) */
    /* ale nie wymaga obslugi 1-elementowej listy */
    move_back_records_no_from(curr_node);

    /* jesli curr_node jest rootem, nie jest wymagana ani dozwolona zadna podmiana wskaznikow */
    if (curr_node != root) {
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

    delete_tram(curr_node->tram);
    curr_node->next = curr_node->prev = NULL;
    free(curr_node);
}


void move_back_records_no_from(struct ListNode* node)
{
    struct ListNode* curr_element;
    for(curr_element=node; curr_element; curr_element=curr_element->next)
        curr_element->record_no--;
}
