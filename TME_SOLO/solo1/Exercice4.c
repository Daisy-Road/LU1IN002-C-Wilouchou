#include <stdio.h>

/* Vous ne devez pas modifier cette fonction */
int valeur(void) {
    int n;

    scanf("%d", &n);
    return n;
}

/* Vous ne devez pas modifier le type de retour de la fonction */
void ma_fonction(int n, int* somme_pos, int* somme_neg) {
    int value;
    *somme_pos = 0;
    *somme_neg = 0;
    for (int i = 0; i < n; i++) {
        value = valeur();
        if (value > 0) *somme_pos += value;
        else if (value < 0) *somme_neg += value;
    }
}

void afficherResultat(int somme_pos, int somme_neg) {
    printf("Somme valeurs positives = %d, Somme valeurs negatives : %d\n",
           somme_pos, somme_neg);
}

/* Vous devez completer la fonction main suivante sans modifier les declarations
   et instructions qui vous sont donnees */
int main() {
    int nb;
    int somme_pos, somme_neg;

    /* Instruction permettant la saisie de la valeur de nb */
    scanf("%d", &nb);

    /* A COMPLETER, remplacez les pointilles */
    ma_fonction(nb, &somme_pos, &somme_neg);

    /* A COMPLETER, remplacez les pointilles */
    afficherResultat(somme_pos, somme_neg);

    return 0;
}
