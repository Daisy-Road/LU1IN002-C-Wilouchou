#ifndef FIFO_H
#define FIFO_H

#include <stdio.h>

typedef struct _Cell {
    int value;
    struct _Cell* next;
} Cell;

typedef struct _FIFO {
    struct _Cell* first;
    struct _Cell* last;
} FIFO;

typedef Cell* FIFOCircular;

FIFO new_fifo();

int is_empty(FIFO f);

FIFO add(int x, FIFO xs);

FIFOCircular addC(int x, FIFOCircular f);

FIFO pop(FIFO xs);

FIFOCircular popC(FIFOCircular xs);

void printFIFO(FIFO xs);

void printFIFOCircular(FIFOCircular xs);

#endif
