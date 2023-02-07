#include <stdio.h>
#define TFAMILLE 57.8
#define TADULTE 22.7
#define TENFANT 10.75

float prixEntree(int adultes, int enfants) {
    float plein_tarif = TADULTE*adultes + TENFANT*enfants;
    float tarif_famille = plein_tarif;
    float min_tarif = plein_tarif;
    int nb_tarif = 0;
    int a_tmp = adultes; int e_tmp = enfants;

    do {
        
        nb_tarif++;
        tarif_famille = nb_tarif*TFAMILLE;

        if(a_tmp >= 2) {
            tarif_famille += TADULTE*(a_tmp-2);
            a_tmp -= 2;
        }
        if(e_tmp >= 3) {
            tarif_famille += TENFANT*(e_tmp-3);
            e_tmp -= 3;
        }
        if(min_tarif > tarif_famille) {
            min_tarif = tarif_famille;
        }

    } while((a_tmp >= 2 || e_tmp >= 3) && (adultes > 0 && enfants > 0));

    if((a_tmp > 0 || e_tmp > 0) && min_tarif > tarif_famille+TFAMILLE) {
        min_tarif = tarif_famille + TFAMILLE;
    }
    
    if(min_tarif > plein_tarif) {
        return plein_tarif;
    } else {
        return min_tarif;
    }
}


int main() {
  int nb_a, nb_e;
  
  scanf("%d",&nb_a);
  scanf("%d",&nb_e);
  
  printf("(%d adulte(s), %d enfant(s)) = %.2f livres\n",nb_a,nb_e,prixEntree(nb_a,nb_e));
  
  return 0;
}
