#include <stdio.h>

void afficheBilletsPieces(int somme) {
    int billets = somme/5;
    int p2 = (somme%5)/2;
    int p1 = (somme%5)%2;
    printf("%d Billet(s) de 5€\n%d Pièce(s) de 2€\n%d Pièce(s) de 1€\n", 
            billets, p2, p1);
}

void afficheBilletsPiecesMultiples(int somme) {
    //TODO à refaire
    //L'objectif est d'itérer avec le nombre maximum de billet de 5
    //Puis ensuite récupérer le nombre de pièces de 2€ restante
    //On retire à chaque fois 2€ pour chaque cas du nombre de billet de 5
    //Puis une fois qu'on a plus de pièce de 2€, on retire un billet de 5€ au maximum
    //repeat
    int nb5, nb2, nb1;
    int somme_tmp=somme;
    nb5=somme_tmp/5;
    while(nb5 >= 0) {
        somme_tmp = somme - (nb5*5);
        nb2 = somme_tmp/2;
        while(nb2 >= 0) {
            nb1 = somme_tmp - (nb2*2);
            printf("(%d, %d, %d)\n",nb5, nb2, nb1);
            nb2--;
        }
        nb5--;
    }
}

int main() {
    afficheBilletsPiecesMultiples(148);
    return 0;
}
