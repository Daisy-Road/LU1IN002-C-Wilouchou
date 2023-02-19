#include <stdio.h>

#define PRIX149 0.07
#define PRIX749 0.06
#define PRIX 0.05

#define PORT200 4
#define PORT500 8
#define PORT 10

float prixPhotos(int qt) {
    float somme = 0;
    // Prix tirage
    if (qt <= 149) {
        somme += PRIX149 * qt;
    } else if (qt <= 749) {
        somme += PRIX749 * qt;
    } else {
        somme += PRIX * qt;
    }

    // Frais de port
    if (qt <= 200) {
        somme += PORT200;
    } else if (qt <= 500) {
        somme += PORT500;
    } else {
        somme += PORT;
    }

    return somme;
}

int main() {
    int quantite;

    /* L'instruction suivante permet de saisir la valeur de la variable
     * quantite. Vous ne devez pas la modifier */
    scanf("%d", &quantite);
    printf("Quantite: %d\n", quantite);

    printf("Prix (port tout compris) %.2f\n", prixPhotos(quantite));
    return 0;
}
