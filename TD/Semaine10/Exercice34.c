#include "utils.h"

cellule_t* Creer_liste_positifs_ite(cellule_t* liste) {
    cellule_t* res = NULL;
    while (liste) {
        if (liste->valeur > 0) { res = Inserer_tete(liste->valeur, res); }
        liste = liste->suivant;
    }
    return res;
}

cellule_t* Creer_liste_positifs(cellule_t* liste) {
    if (!liste) return NULL;
    if (liste->valeur > 0)
        return Inserer_tete(liste->valeur,
                            Creer_liste_positifs(liste->suivant));
    else return Creer_liste_positifs(liste->suivant);
}

cellule_t* Garder_positif(cellule_t* liste) {
    if (!liste) return NULL;
    if (liste->valeur <= 0) {
        cellule_t* tmp = liste->suivant;
        free(liste);
        return tmp;
    }
    liste->suivant = Garder_positif(liste->suivant);
    return liste;
}

int main() {
    int tab[5] = {-1, 2, -3, 4, -5};
    cellule_t* test = gen_list(tab, 5);
    print(test);
    print(Garder_positif(test));
    return 0;
}
