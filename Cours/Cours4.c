#include <stdlib.h>
#include <stdio.h>

float* mettre_au_carre(float tab[], int len) { //Retourne un tableau dynamique
    float* tab2 = malloc(sizeof(float)*len); //Allocation de mémoire sur le tas
    int i;
    for(i=0; i < len; i++) {
        tab2[i] = tab[i] * tab[i];
    }
    return tab2;
}

int main() {
    float tab[5] = {1, 2, 3, 4, 5};
    float* tab_carre = mettre_au_carre(tab, 5);
    int i;
    for(i=0; i < 5; i++) {
        printf("%f\n", tab_carre[i]);
        NULL;
    }
    free(tab_carre); // Libération du tas
    return 0;
}
