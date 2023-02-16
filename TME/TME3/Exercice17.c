#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_VALEURS 50
#define VMIN -20
#define VMAX 20

int valeur_aleatoire(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void pos_neg_zero(int value, int* count_neg, int* count_pos, int* count_zero) {
    if (value > 0) {
        ++*count_pos;
        return;
    }
    if (value < 0) {
        ++*count_neg;
        return;
    }
    ++*count_zero;
}

int main() {

    /* initialisation du générateur de nombres aléatoires */
    srand(time(NULL));
    int nb_negatif = 0;
    int nb_positif = 0;
    int nb_z = 0;
    for (int i = 0; i < NB_VALEURS; i++) {
        int random = valeur_aleatoire(VMIN, VMAX);
        pos_neg_zero(random, &nb_negatif, &nb_positif, &nb_z);
    }
    printf("Positif: %d | Négatif: %d | Zéros: %d\n", nb_positif, nb_negatif,
           nb_z);

    return 0;
}
