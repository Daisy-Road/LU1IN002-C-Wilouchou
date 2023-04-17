#include <stdio.h>
#include <stdlib.h>

typedef struct _cellule_t cellule_t;
struct _cellule_t {
    int donnee;
    cellule_t* suivant;
};

typedef struct _element_t element_t;
struct _element_t {
    int valeur;
    int frequence;
    element_t* suivant;
};

element_t* Creer_multi_ensemble_liste(cellule_t* list) {
    element_t* res = NULL;
    element_t* new_el = NULL;
    while (list) {
        new_el = malloc(sizeof(element_t));
        new_el->valeur = list->donnee;
    }
}

int main() { return 0; }
