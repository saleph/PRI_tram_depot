#ifndef TRAMS_LIST_H_INCLUDED
#define TRAMS_LIST_H_INCLUDED

#include "tram.h"

struct ListNode {
    int record_no;
    Tram* tram;
    struct ListNode* prev;
    struct ListNode* next;
};
extern struct ListNode* root;

void append_tram(int, char*, int, char*, char*);
void edit_tram_with_index(int, int, char*, int, char*, char*);
void delete_tram_with_index(int);
void print_the_list();

void move_back_records_no_from(struct ListNode*);

#endif /* TRAMS_LIST_H_INCLUDED */
