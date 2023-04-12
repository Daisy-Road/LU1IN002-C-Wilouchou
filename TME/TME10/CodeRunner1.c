#include "utils.h"

int taille(element_t* ens) {
    if(!ens) return 0;
    else return ens->frequence+taille(ens->suivant);
}

element_t* supprime_frequence_inf_seuil(element_t* ens, int seuil) {
    element_t* prev = NULL;
    element_t* res = ens;
    while(ens) {
        if(ens->frequence >= seuil) { 
            prev = ens;
            ens = ens->suivant;
            continue;
        }
        element_t* tmp = ens->suivant;
        free(ens);
        if(prev) prev->suivant = tmp;
        else res = tmp; 
        ens = tmp; 
    }
    return res;
}

element_t* ajout_suivant(element_t* element, int val, int freq) {
    element_t* new_el = malloc(sizeof(element));
    new_el->valeur = val;
    new_el->frequence = freq;
    new_el->suivant = NULL;
    if(!element) return new_el;
    new_el->suivant = element->suivant;
    element->suivant = new_el;
    return new_el;
}

int main() {
   int n;
   scanf("%d", &n);
   /* creation d'un multi-ensemble contenant n valeurs differentes */
   element_t* multiE = creer_multiEnsemble(n);
   print(multiE);
   multiE = supprime_frequence_inf_seuil(multiE, 5);
   print(multiE);
   return 0;
}
