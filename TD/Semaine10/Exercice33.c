#include "utils.h"

cellule_t* Renvoyer_element_debut_rec(int val, cellule_t* liste) {
    if (!liste) return NULL;
    else if (liste->valeur == val) return liste;
    else return Renvoyer_element_debut_rec(val, liste->suivant);
}

cellule_t* Inserer_fin_rec(int d, cellule_t* liste) {
    if (!liste) return creer_cellule(d);
    liste->suivant = Inserer_fin_rec(d, liste->suivant);
    return liste;
}

cellule_t* Supprimer_en_pos_rec(int pos, cellule_t* liste) {
    if (!liste) return NULL;
    if (pos == 0) {
        cellule_t* tmp = liste->suivant;
        free(liste);
        return tmp;
    }
    liste->suivant = Supprimer_en_pos_rec(pos - 1, liste->suivant);
    return liste;
}

int main() { return 0; }
