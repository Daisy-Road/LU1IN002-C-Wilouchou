#include <stdio.h>

/* Vous ne devez pas modifier cette fonction */
int valeur() {
    int n;
    scanf("%d ", &n);
    return n;
}

/* NB: La question n'a RIEN DE FRANCAIS et ne veut rien dire.
 * Reformulation... L'objectif est de demander n valeurs à l'utilisateur
 * On ajoute la valeur à la somme à retourner si cette valeur est inférieure
 * à la borne. */

int somme(int n, int borne) {
    int somme = 0;
    int value;
    for (int i = 0; i < n; i++) {
        value = valeur();
        if (value < borne)
            somme += value;
    }
    return somme;
}

int main() {
    int borne, n;

    /* Les deux instructions suivantes permettent la saisie la valeur
     * des variables borne et n.
     * Vous ne devez pas les modifier */
    scanf("%d ", &borne);
    scanf("%d ", &n);
    printf("Borne : %d, Nb valeurs : %d\n", borne, n);

    printf("somme = %d\n", somme(n, borne));
    return 0;
}
