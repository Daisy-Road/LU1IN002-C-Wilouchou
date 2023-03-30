#include "TD9Utils.h"
#include <stdlib.h>

List* freeList(List* list) {
    List* f = list;
    while (list) {
        free(f);
        list = list->next;
        f = list;
    }
    return NULL;
}

List* freePos(size_t pos, List* list) {
    List* prev = NULL;
    List* lcpy = list;
    while (list && pos != 0) {
        prev = list;
        list = list->next;
        pos--;
    }
    if (!prev) {
        List* res = list->next;
        free(list);
        return res;
    }
    prev->next = list->next;
    free(list);
    return lcpy;
}

int main() {
    List* l = generateList(10);
    printList(l);
    return 0;
}
