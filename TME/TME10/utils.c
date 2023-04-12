#include "utils.h"

element_t* creer_multiEnsemble(int n) {
    element_t* res = NULL;
    int val;
    int freq;
    for(int i=0; i<n; i++) {
        scanf("%d", &val);
        scanf("%d", &freq);
        res = ajout_tete_ensemble(res, val, freq);
    }
    return res;
}

element_t* ajout_tete_ensemble(element_t *ensemble, int val, int freq) {
    element_t* new_el = malloc(sizeof(element_t));
    new_el->valeur = val;
    new_el->frequence = freq;
    new_el->suivant = ensemble;
    return new_el;
}

void print(element_t* ens) {
    printf("{");
    while(ens && ens->suivant) {
        printf("(%d, %d), ", ens->valeur, ens->frequence);
        ens = ens->suivant;
    }
    if(ens) printf("(%d, %d)", ens->valeur, ens->frequence);
    printf("}\n");
}
