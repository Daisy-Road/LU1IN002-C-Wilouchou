#include "TME9Utils.h"

element_t* Recherche_val(element_t* ensemble, int val) {
    if (!ensemble || ensemble->valeur == val) return ensemble;
    else return Recherche_val(ensemble->suivant, val);
}

element_t* Ajout_tete_ensemble(element_t* ensemble, int val, int freq) {
    element_t* ptr = Recherche_val(ensemble, val);
    if (ptr) {
        ptr->frequence += freq;
        return ensemble;
    }
    element_t* new_el = malloc(sizeof(element_t));
    new_el->valeur = val;
    new_el->frequence = freq;
    new_el->suivant = ensemble;
    return new_el;
}
