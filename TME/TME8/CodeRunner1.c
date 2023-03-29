#include "CodeRunnerUtils.h"
#include <stdio.h>
#include <stdlib.h>

int nb_occurences(int val, cellule_t* liste) {
    if (!liste) return 0;
    if (val != liste->donnee) return 0 + nb_occurences(val, liste->suivant);
    else return 1 + nb_occurences(val, liste->suivant);
}

int tous_plus_grands(int val, cellule_t* liste) {
    while (liste) {
        if (liste->donnee < val) return 0;
        liste = liste->suivant;
    }
    return 1;
}

int tous_plus_grands_recu(int val, cellule_t* liste) {
    if (!liste) return 1;
    else if (liste->donnee < val) return 0;
    return tous_plus_grands_recu(val, liste->suivant);
}

cellule_t* maximum(cellule_t* liste) {
    if (!liste) return liste;
    cellule_t* res = liste;
    liste = liste->suivant;
    while (liste) {
        if (res->donnee < liste->donnee) res = liste;
        liste = liste->suivant;
    }
    return res;
}

int renvoyer_val_element_pos(int pos, cellule_t* liste) {
    if (pos == 0) return liste->donnee;
    else return renvoyer_val_element_pos(pos - 1, liste->suivant);
}

int main() {
    int el, n;
    scanf("%d", &n);
    /* creation d'une liste de n elements */
    cellule_t* ma_liste = creerListe(n);
    afficheListe(ma_liste);
    scanf("%d", &el);
    printf("%d\n", nb_occurences(el, ma_liste));
    //    printf("%d\n", tous_plus_grands(el, ma_liste));
    return 0;
}
