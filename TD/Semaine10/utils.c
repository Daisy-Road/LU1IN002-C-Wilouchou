#include "utils.h"

cellule_t* creer_cellule(int d) {
    cellule_t* res = malloc(sizeof(cellule_t));
    res->valeur = d;
    res->suivant = NULL;
    return res;
}

cellule_t* Inserer_tete(int d, cellule_t* liste) {
    cellule_t* res = creer_cellule(d);
    res->suivant = liste;
    return res;
}

void print(cellule_t* table) {
    printf("{");
    while (table && table->suivant) {
        printf("%d, ", table->valeur);
        table = table->suivant;
    }
    if (table) printf("%d", table->valeur);
    printf("}\n");
}

cellule_t* gen_list(int tab[], size_t len) {
    cellule_t* res = NULL;
    for (int i = len - 1; i > 0; i--) {
        res = Inserer_tete(tab[i], res);
    }
    return res;
}
