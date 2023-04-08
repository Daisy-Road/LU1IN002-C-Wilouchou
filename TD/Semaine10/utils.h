#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct _cellule_t {
    int valeur;
    struct _cellule_t* suivant;
} cellule_t;

cellule_t* creer_cellule(int d);
cellule_t* Inserer_tete(int d, cellule_t* liste);
cellule_t* gen_list(int tab[], size_t len);
void print(cellule_t* liste);
