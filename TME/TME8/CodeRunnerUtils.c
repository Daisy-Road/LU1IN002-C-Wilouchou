#include "CodeRunnerUtils.h"
#include <stdio.h>
#include <stdlib.h>

cellule_t* creerListe(int n) {
    if (n == 0) return NULL;
    cellule_t* res = malloc(sizeof(cellule_t));
    printf("Enter value: ");
    scanf("%d", &(res->donnee));
    res->suivant = creerListe(n - 1);
    return res;
}

void afficheListe(cellule_t* list) {
    if (!list) {
        printf("{}\n");
        return;
    }
    printf("{");
    while (list->suivant) {
        printf("%d, ", list->donnee);
        list = list->suivant;
    }
    printf("%d}\n", list->donnee);
    return;
}
