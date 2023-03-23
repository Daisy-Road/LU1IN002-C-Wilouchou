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

void free_list_recu(List* list) {
    if (!list) return;
    free_list_recu(list->next);
    free(list);
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

List* remove_el(List* list, int val) {
    if (!list) return NULL;
    if (list->value == val) {
        List* tmp = list->next;
        free(list);
        return tmp;
    }
    list->next = remove_el(list->next, val);
    return list;
}

List* remove_el_it(List* list, int val) {
    List* start = list;
    if (list && list->value == val) {
        List* tmp = list->next;
        free(list);
        return tmp;
    }
    List* prev = list;
    list = list->next;
    while (list) {
        if (list->value == val) {
            prev->next = list->next;
            free(list);
            return prev;
        }
        List* prev = list;
        list = list->next;
    }
    return start;
}

List* new_list_square(List* list) {
    List* res = NULL;
    List* last = NULL;
    while (list) {
        List* new = new_list(list->value * list->value);
        if (!res) {
            res = new;
            last = new;
        } else {
            last->next = new;
            last = new;
        }
        list = list->next;
    }
    return res;
}
