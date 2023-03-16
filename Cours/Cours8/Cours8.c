#include "listes.h"
#include <stdio.h>
#include <stdlib.h>
// Cours: Les listes chainées

/* Pour définir une liste chaînée, on utilise une structure
 * qui sera récursive, et qui liera un élément à un autre
 * en utilisant une adresse.
 *
 * Cela permet donc d'ajouter un élément sans décaler les autres
 * simplement en modifiant l'adresse "next" de l'élément précédent.
 *
 * Evidemment, la liste est constitué d'une "tête" et d'une "queue".
 * La queue contiendra le pointeur NULL
 * La tête contiendra la première valeur de la liste, et sera pointé
 * lors de la création de la liste.
 *
 * On pourrait aussi faire une liste circulaire
 * Dans ce cas là, la "queue" pointe vers la "tête" */

int main(int argc, char** argv) {
    List* list = NULL;
    for (int i = 1; i < argc; i++) {
        list = add_el(list, new_list(atoi(argv[i])));
    }
    print_list(stdout, list);
    printf("%d\n", sum_list(list));
    int value;
    printf("What value we want to search for ? ");
    scanf("%d", &value);
    printf("\n");
    printf("%p\n", find_val(list, value));
    free_list(list);
    return 0;
}
