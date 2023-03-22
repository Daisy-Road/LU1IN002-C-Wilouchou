#include <stdio.h>
#include <stdlib.h>

typedef struct _cellule_t cellule_t;
struct _cellule_t {
    int donnee;
    cellule_t* suivant;
};

cellule_t* f(int d, cellule_t* liste) {
    cellule_t* nCell;
    if (liste == NULL) {
        nCell = malloc(sizeof(cellule_t));
        nCell->donnee = d;
        nCell->suivant = NULL;
        return nCell;
    }

    liste->suivant = f(d, liste->suivant);
    return liste;
}

void affiche(cellule_t* liste) {
    while (liste != NULL) {
        printf("%d ", liste->donnee);
        liste = liste->suivant;
    }
}

int main() {
    cellule_t last = {17, NULL};
    cellule_t second = {15, &last};
    cellule_t first = {12, &second};
    cellule_t* liste = &first;
    liste = f(15, liste);
    affiche(liste);
    printf("\n");
}
