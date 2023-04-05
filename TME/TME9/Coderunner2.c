#include "TME9Utils.h"

element_t* Supprime_total_element(element_t* ensemble, int val) {
    if (ensemble->valeur == val) {
        element_t* res = ensemble->suivant;
        free(ensemble);
        return res;
    }
    element_t* cp = ensemble;
    while (cp->suivant->valeur != val) {
        cp = cp->suivant;
        if (!cp->suivant) return ensemble;
    }
    element_t* tmp = cp->suivant->suivant;
    free(cp->suivant);
    cp->suivant = tmp;
    return ensemble;
}

element_t* Supprime_element(element_t* ensemble, int val) {
    element_t* prev = NULL;
    element_t* res = ensemble;
    while (ensemble->valeur != val) {
        prev = ensemble;
        ensemble = ensemble->suivant;
        if (!ensemble) return res;
    }
    if (ensemble->frequence > 1) ensemble->frequence--;
    else if (!prev) {
        res = ensemble->suivant;
        free(ensemble);
    } else {
        prev->suivant = ensemble->suivant;
        free(ensemble);
    }
    return res;
}

int main() {
    element_t* ens = CreationMultiEnsemble(5);
    print(ens);
    for (int i = 0; i < 10; i++)
        ens = Supprime_element(ens, 6);
    print(ens);
}
