#include "utils.h"

int inclus_rec(element_t* ens1, element_t* ens2) {
    if(!ens2) return ens1 == NULL;
    if(!ens1) return 1;
    if(ens1->valeur < ens2->valeur) return 0;
    if(ens1->valeur == ens2->valeur){
        if(ens1->frequence <= ens2->frequence) return inclus_rec(ens1->suivant, ens2->suivant);  
        else return 0;
    } 
    return inclus_rec(ens1, ens2->suivant);
}

element_t* unionME(element_t* ens1, element_t* ens2) {
    element_t* res = NULL;
    while(ens1 && ens2) {
        if(ens1->valeur < ens2->valeur) {
            res = ajout_tete_ensemble(res, ens1->valeur, ens1->frequence);
            ens1 = ens1->suivant;
            continue;
        }
        if(ens1->valeur > ens2->valeur) {
            res = ajout_tete_ensemble(res, ens2->valeur, ens2->frequence);
            ens2 = ens2->suivant;
            continue;
        }
        res = ajout_tete_ensemble(res, ens1->valeur, ens1->frequence + ens2->frequence);
        ens1 = ens1->suivant;
        ens2 = ens2->suivant;
    }
    while(ens1) {
        res = ajout_tete_ensemble(res, ens1->valeur, ens1->frequence);
        ens1 = ens1->suivant;
    }
    while(ens2) {
        res= ajout_tete_ensemble(res, ens2->valeur, ens2->frequence);
        ens2 = ens2->suivant;
    }
    return res;
}

int main() {
   int n1, n2;
   scanf("%d", &n1);
   /* creation d'un multi-ensemble trie contenant n1 valeurs differentes */
   element_t* multiE1 = creer_multiEnsemble(n1);
   scanf("%d", &n2);
   /* creation d'un multi-ensemble trie contenant n2 valeurs differentes */
   element_t* multiE2 = creer_multiEnsemble(n2);
   printf("Union : ");
   print(unionME(multiE1, multiE2));
   /* on affiche les ensembles APRES (l'union ne doit pas modifier les listes) */
   printf("multiE1 : ");
   print(multiE1);
   printf("multiE2 : ");
   print(multiE2);
   return 0;
}
