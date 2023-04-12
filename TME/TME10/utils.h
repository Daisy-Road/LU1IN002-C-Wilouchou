#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct _element_t element_t;

struct _element_t {
    int valeur;
    int frequence;
    element_t* suivant;
};

element_t* creer_multiEnsemble(int n);
element_t* ajout_tete_ensemble(element_t *ensemble, int val, int freq);
void print(element_t* ent);
