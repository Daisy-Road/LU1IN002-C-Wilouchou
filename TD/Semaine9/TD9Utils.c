#include "TD9Utils.h"
#include <stdio.h>
#include <stdlib.h>

List* generateList(int size) {
    if (size == 0) return NULL;
    List* list = malloc(sizeof(List));
    list->value = size;
    list->next = generateList(size - 1);
    return list;
}

void printList(List* list) {
    printf("{");
    while (list) {
        printf("%d", list->value);
        if (!list->next) break;
        printf(", ");
        list = list->next;
    }
    printf("}\n");
}
