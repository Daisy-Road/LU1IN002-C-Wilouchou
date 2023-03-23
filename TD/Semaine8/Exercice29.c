#include "Exercice28.h"
#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

size_t len(List* list) {
    if (!list) return 0;
    return 1 + len(list->next);
}

int existe(List* list, int val) {
    if (!list) return 0;
    if (list->value == val) return 1;
    return existe(list->next, val);
}

List* first_el(List* list, int val) {
    if (!list) return NULL;
    if (list->value == val) return list;
    return first_el(list->next, val);
}

List* last_el(List* list, int val) {
    List* res = NULL;
    while (list) {
        if (list->value == val) res = list;
        list = list->next;
    }
    return res;
}

List* last_cell(List* list) {
    if (!list) return NULL;
    if (!list->next) return list;
    return last_cell(list->next);
}

List* modify_el(int val, size_t pos, List* list) {
    int i = 0;
    while (i < pos && list) {
        i++;
        list = list->next;
    }
    if (i < pos) {
        fprintf(stderr, "ERROR: Index provided was higher than the size of the "
                        "list evaluated.\n");
        return NULL;
    }
    list->value = val;
    return list;
}

List* modify_el_recu(int val, size_t pos, List* list) {
    if (!list) {
        fprintf(stderr, "ERROR: Index provided was higher than the size of the "
                        "list evaluated.\n");
        return NULL;
    }
    if (pos == 0) {
        list->value = val;
        return list;
    }
    return modify_el_recu(val, pos - 1, list->next);
}

int main() {
    List* tete = NULL;
    tete = new_cell(1);
    tete->next = new_cell(2);
    tete->next->next = new_cell(3);
    printf("%lu\n", len(tete));
    modify_el_recu(4, 1, tete);
    print_list(tete);
    modify_el_recu(3, 5, tete);
    return 0;
}
