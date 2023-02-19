#include <stdio.h>

/* Vous ne devez pas modifier cette fonction */
int valeur(void) {
    int n;

    scanf("%d ", &n);
    return n;
}

/* Vous ne devez pas modifier le type de retour de la fonction */
void ma_fonction(int n, int* somme, int* carre) {
    *somme = 0;
    *carre = 0;
    int value;
    for (int i = 0; i < n; i++) {
        value = valeur();
        *somme += value;
        *carre += value * value;
    }
}

void afficherResultat(int somme, int somme_carres) {
    printf("Somme=%d, Sommes carres=%d\n", somme, somme_carres);
}

/* Vous devez completer la fonction main suivante sans modifier les déclarations
 * et instrcutions
 * qui vous sont donnees */

int main() {
    int nb;
    int somme, somme_carres;

    /* Instruction permettant la saisie de la valeur de nb */
    scanf("%d ", &nb);

    /* A COMPLETER, remplacez les pointilles */
    ma_fonction(nb, &somme, &somme_carres);

    /* A COMPLETER, remplacez les pointilles */
    afficherResultat(somme, somme_carres);

    return 0;
}
