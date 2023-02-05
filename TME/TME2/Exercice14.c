#include <stdio.h>

#define TADULTE 22.7
#define TENFANTS 10.75
#define TFAMILLE 57.80

float prixEntree(int adultes, int enfants);


int main() {
    printf("Meilleur tarif: %.2f£\n",prixEntree(5, 7));
    return 0;
}

float prixEntree(int adultes, int enfants) {
    float plein_tarif = TADULTE*adultes + TENFANTS*enfants;
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
            tarif_famille += TENFANTS*(e_tmp-3);
            e_tmp -= 3;
        }
        if(min_tarif > tarif_famille) {
            min_tarif = tarif_famille;
        }

    } while((a_tmp >= 2 || e_tmp >= 3) && (adultes > 0 && enfants > 0));

    if((a_tmp > 0 || e_tmp > 0) && min_tarif > tarif_famille+TFAMILLE) {
        min_tarif = tarif_famille + TFAMILLE;
    }
    
    printf("Le plus optimisé serait %d tarifs famille !\n", nb_tarif);
    if(min_tarif > plein_tarif) {
        return plein_tarif;
    } else {
        return min_tarif;
    }

}
