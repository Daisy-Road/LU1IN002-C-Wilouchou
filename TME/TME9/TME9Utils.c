#include "TME9Utils.h"
#include <stdio.h>

element_t* CreationMultiEnsemble(int n) {
    element_t* l = malloc(sizeof(element_t));
    element_t* res = l;
    res->valeur = 1;
    res->frequence = 2;
    for (int i = 2; i < n + 1; i++) {
        element_t* cell = malloc(sizeof(element_t));
        l->suivant = cell;
        l = l->suivant;
        l->frequence = 2 * i;
        l->valeur = i;
    }
    l->suivant = NULL;
    return res;
}

element_t* CreationMultiEnsemble_2_2(int n) {
    element_t* l = malloc(sizeof(element_t));
    element_t* res = l;
    res->valeur = 2;
    res->frequence = 4;
    for (int i = 4; i < 2 * n + 1; i += 2) {
        element_t* cell = malloc(sizeof(element_t));
        l->suivant = cell;
        l = l->suivant;
        l->frequence = i;
        l->valeur = i;
    }
    l->suivant = NULL;
    return res;
}

void print(element_t* table) {
    printf("{");
    while (table->suivant) {
        printf("(%d, %d), ", table->valeur, table->frequence);
        table = table->suivant;
    }
    printf("(%d, %d)}\n", table->valeur, table->frequence);
}
