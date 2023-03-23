#ifndef LIST_
#define LIST_

#include <stdio.h>

typedef struct _List {
    int value;
    struct _List* next;
} List;

List* new_list(int value);

void print_list(FILE* flux, List* list);

List* add_el(List* list, List* new_el);

void free_list(List* list);

void free_list_recu(List* list);

int sum_list(List* list);

List* find_val(List* list, int val);

List* remove_el(List* list, int val);

List* remove_el_it(List* list, int val);

List* add_el_recu(List* list, List* new_cell);

List* new_list_squared(List* list);

#endif
