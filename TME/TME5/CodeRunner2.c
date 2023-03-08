#include <stdio.h>
#include <stdlib.h>

#define NB_JOURS 8
#define NB_AMIS 4

void afficheTableau(float tab[][NB_JOURS], int taille) {
    int j, i;

    for (i = 0; i < taille; i++) {
        printf("AMI %d : ", i + 1);
        for (j = 0; j < NB_JOURS; j++) {
            printf(" Jour %d : %3.2f", j + 1, tab[i][j]);
        }
        printf("\n");
    }
}

void init_zero(float tab[][NB_JOURS], int taille) {
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < NB_JOURS; j++) {
            tab[i][j] = 0;
        }
    }
}

void affecte_depenses(float tab[][NB_JOURS], int jour, float montant, int id) {
    for (int i = 0; i < NB_AMIS; i++) {
        tab[i][jour] = (id != i) ? -(montant / NB_AMIS)
                                 : (montant / NB_AMIS) * (NB_AMIS - 1);
    }
}

float calcul_solde(float tab[][NB_JOURS], int id) {
    float res = 0.0;
    for (int i = 0; i < NB_JOURS; i++) {
        res += tab[id][i];
    }
    return res;
}

void affiche_soldes(float tab[][NB_JOURS]) {

    /* format d'affichage a respecter pour chaque membre
    du groupe */
    for (int i = 0; i < NB_AMIS; i++) {
        printf("Solde pour %d : %.2f\n", i, calcul_solde(tab, i));
    }
}

int main() {
    {
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
        ;
    }
    return 0;
}
