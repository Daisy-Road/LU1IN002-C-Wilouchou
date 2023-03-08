#include <stdio.h>
#include <stdlib.h>

#define NB_JOURS 4
#define NB_AMIS 8

void init_zero(float tab[][NB_JOURS], int taille) {

    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < NB_JOURS; j++) {
            tab[i][j] = 0;
        }
    }
}

void aaffecte_depenses(float tab[][NB_JOURS], int jour, float montant, int id) {
    float dette = -(montant / NB_AMIS);
    float avoir = montant + dette;

    tab[id][jour] = avoir;

    for (int i = 0; i < NB_AMIS; i++) {
        if (i != id) { tab[i][jour] = dette; }
    }
}

void affecte_depenses(float tab[][NB_JOURS], int jour, float montant, int id) {
    for (int i = 0; i < NB_AMIS; i++) {
        tab[i][jour] = (id != i) ? -(montant / NB_AMIS)
                                 : (montant / NB_AMIS) * (NB_AMIS - 1);
    }
}

void afficheTableau(float tab[][NB_JOURS], int taille) {
    int j, i;

    for (i = 0; i < taille; i++) {
        printf("AMI %d : ", i);
        for (j = 0; j < NB_JOURS; j++) {
            printf(" Jour %d : %3.2f", j, tab[i][j]);
        }
        printf("\n");
    }
}

int main() {
    float depenses[NB_AMIS][NB_JOURS];
    init_zero(depenses, NB_AMIS);
    affecte_depenses(depenses, 0, 37.0, 1);
    affecte_depenses(depenses, 1, 32.0, 2);
    affecte_depenses(depenses, 2, 43.0, 0);
    affecte_depenses(depenses, 3, 39.0, 2);
    affecte_depenses(depenses, 4, 38.0, 1);
    affecte_depenses(depenses, 5, 36.0, 1);
    affecte_depenses(depenses, 6, 30.0, 2);
    afficheTableau(depenses, NB_AMIS);
    return 0;
}
