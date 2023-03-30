#pragma once

typedef struct _List {
    int value;
    struct _List* next;
} List;

List* generateList(int size);

void printList(List* list);
