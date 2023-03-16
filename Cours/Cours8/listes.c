#include "listes.h"
#include <stdio.h>
#include <stdlib.h>

List* new_list(int value) {
    List* res = malloc(sizeof(List));
    if (res == NULL) {
        fprintf(stderr, "Allocation error when trying to create a list");
        exit(1);
    }
    res->value = value;
    res->next = NULL;
    return res;
}

void print_list(FILE* flux, List* list) {
    if (!list) return; // For empty list, we exit immediatly
    printf("{");
    while (list->next) {
        fprintf(flux, "%d, ", list->value);
        list = list->next;
    }
    printf("%d}\n", list->value);
}

List* add_el(List* list, List* new_el) {
    if (list == NULL) return new_el;
    List* cp_list = list;
    while (list->next) {
        list = list->next;
    }
    list->next = new_el;
    return cp_list;
}

void free_list(List* list) {
    while (list) {
        List* tmp = list->next;
        free(list);
        list = tmp;
    }
}

int sum_list(List* list) {
    if (!list) return 0;
    return list->value + sum_list(list->next);
}

List* find_val(List* list, int val) {
    if (!list) return NULL;
    if (list->value == val) return list;
    return find_val(list->next, val);
}
