#include "FIFO.h"
#include <stdio.h>
#include <stdlib.h>

FIFO new_fifo() {
    FIFO r = {NULL, NULL};
    return r;
}

int is_empty(FIFO f) { return (f.first == NULL && f.last == NULL); }

FIFO add(int x, FIFO xs) {
    Cell* c = malloc(sizeof(Cell));
    c->value = x;
    c->next = NULL;

    if (is_empty(xs)) {
        xs.first = c;
        xs.last = c;
    } else {
        xs.last->next = c;
        xs.last = c;
    }
    return xs;
}

FIFOCircular addC(int x, FIFOCircular xs) {
    Cell* c = malloc(sizeof(Cell));
    c->value = x;

    if (!xs) {
        c->next = c;
    } else {
        c->next = xs->next;
    }
    return c;
}

FIFO pop(FIFO xs) {
    if (!is_empty(xs)) {
        Cell* tmp = xs.first;
        xs.first = xs.first->next;
        if (!xs.first) xs.last = NULL; // Si la liste n'a qu'un seul élément
        free(tmp);
    }
    return xs;
}

FIFOCircular popC(FIFOCircular xs) {
    if (xs) {
        Cell* tmp = xs->next;
        xs->next = xs->next->next;
        if (xs->next == xs) xs = NULL; // La liste n'avait qu'un seul élément
        free(tmp);
    }
    return xs;
}

void printFIFO(FIFO xs) {
    printf("{");
    if (!is_empty(xs)) {
        Cell* c = xs.first;
        while (c->next) {
            printf("%d, ", c->value);
            c = c->next;
        }
        printf("%d", c->value);
    }
    printf("}");
}

void printFIFOCircular(FIFOCircular xs) {
    printf("{");
    if (xs) {
        Cell* c = xs->next;
        while (c != xs) {
            printf("%d, ", c->value);
            c = c->next;
        }
        printf("%d", c->value);
    }
    printf("}");
}
