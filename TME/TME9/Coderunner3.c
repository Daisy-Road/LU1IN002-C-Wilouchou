#include "TME9Utils.h"

element_t* Ajout_ensemble_trie(element_t* ensemble, int val, int freq) {
    element_t* new = malloc(sizeof(element_t));
    new->valeur = val;
    new->frequence = freq;
    if (!ensemble) return new;
    element_t* prev = NULL;
    element_t* cp = ensemble;
    while (cp && cp->valeur <= val) {
        if (cp->valeur == val) {
            cp->frequence += freq;
            return ensemble;
        }
        prev = cp;
        cp = cp->suivant;
    }
    if (!prev) {
        new->suivant = ensemble;
        return new;
    } else {
        prev->suivant = new;
        new->suivant = cp;
    }
    return ensemble;
}

element_t* Supprime_total_element_ensemble_trie(element_t* ensemble, int val) {
    element_t* prev = NULL;
    element_t* cp = ensemble;
    while (cp && cp->valeur < val) {
        prev = cp;
        cp = cp->suivant;
    }
    if (!cp || cp->valeur != val) return ensemble;
    if (!prev) {
        element_t* tmp = ensemble->suivant;
        free(ensemble);
        return tmp;
    }
    prev->suivant = cp->suivant;
    free(cp);
    return ensemble;
}

element_t* Supprime_element_ensemble_trie(element_t* ensemble, int val) {
    element_t* prev = NULL;
    element_t* cp = ensemble;
    while (cp && cp->valeur < val) {
        prev = cp;
        cp = cp->suivant;
    }
    if (!cp || cp->valeur != val) return ensemble;
    if (cp->frequence > 1) {
        cp->frequence--;
        return ensemble;
    }
    if (!prev) {
        element_t* tmp = ensemble->suivant;
        free(ensemble);
        return tmp;
    }
    prev->suivant = cp->suivant;
    free(cp);
    return ensemble;
}

int main() {
    element_t* ens = CreationMultiEnsemble_2_2(4);
    print(ens);
    ens = Ajout_ensemble_trie(ens, 9, 1);
    print(ens);
    ens = Supprime_total_element_ensemble_trie(ens, 10);
    print(ens);
}
