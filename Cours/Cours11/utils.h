#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct _Dictionary {
    char* key;
    int value;
    struct _Dictionary* next;
} Dictionary;

typedef struct _TabHash {
    size_t size;
    struct _Dictionary** tab;
} TabHash;

TabHash* createTabH(size_t Nb);
int hash(TabHash* th, char* key);
void add(TabHash* th, char* key, int value);
void printTabHash(TabHash* th);
TabHash* freeTabH(TabHash* th);
