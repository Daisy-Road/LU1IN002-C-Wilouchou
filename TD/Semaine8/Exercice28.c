#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

List* new_cell(int value) {
    List* res = malloc(sizeof(List));
    res->value = value;
    res->next = NULL;
    return res;
}

void print_list(List* list) {
    if (!list) printf("(nil)");
    printf("{");
    while (list->next) {
        printf("%d, ", list->value);
        list = list->next;
    }
    printf("%d}\n", list->value);
}

int main() {
    List* tete = NULL;
    tete = new_cell(1);
    tete->next = new_cell(2);
    tete->next->next = new_cell(3);
    print_list(tete);
    return 0;
}
