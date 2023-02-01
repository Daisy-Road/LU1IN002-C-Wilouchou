#include <stdio.h>
#define TFAMILLE 57.8
#define TADULTE 22.7
#define TENFANT 10.75

float prixEntree(int adultes, int enfants){
  float prix_base = adultes*22.7 + enfants*10.75;
  float prix_formule = 57.8;
  if(adultes > 2) {
    prix_formule = prix_formule + (adultes-2)*22.7;
  }
  if(enfants > 3) {
    prix_formule = prix_formule + (enfants-3)*10.75;
  }
  if(prix_base > prix_formule) {
    return prix_formule;
  } else {
    return prix_base;
  }
}
 


int main() {
  int nb_a, nb_e;
  
  scanf("%d",&nb_a);
  scanf("%d",&nb_e);
  
  printf("(%d adultes, %d enfants) = %.2f livres\n",nb_a,nb_e,prixEntree(nb_a,nb_e));
  
  return 0;
}
