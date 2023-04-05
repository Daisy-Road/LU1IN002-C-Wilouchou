#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct _element_t element_t;
struct _element_t {
    int valeur;
    int frequence;
    element_t* suivant;
};
element_t* CreationMultiEnsemble(int n);
element_t* CreationMultiEnsemble_2_2(int n);

void print(element_t* table);
