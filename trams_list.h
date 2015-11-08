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
extern int list_size;

/* funkcje zewnetrzne */
void append_tram(int, char*, int, char*, char*);
void edit_tram_with_index(int, int, char*, int, char*, char*);
void delete_tram_with_index(int);

void print_the_list_by_record_no();
void print_the_list_by_line_no();
void print_the_list_by_tram_type();


/* funkcje wewnetrzne */
void move_back_records_no_from(struct ListNode*);

struct ListNode** create_nodes_array();
void delete_nodes_array(struct ListNode**);

void sort_by_line_no(struct ListNode**);
void sort_by_tram_type(struct ListNode**);

void swap_nodes(struct ListNode**, struct ListNode**);

#endif /* TRAMS_LIST_H_INCLUDED */
