#include <stdio.h>
#include <stdlib.h>

int* fusion(int tab1[], int taille1, int tab2[], int taille2) {
    /* realise la fusion triee des tableaux tries tab1 et tab2 */
    int* tab = malloc((taille1 + taille2) * sizeof(int));
    int index1 = 0;
    int index2 = 0;
    for (int i = 0; i < (taille1 + taille2); i++) {
        if (taille1 > index1 &&
            (index2 == taille2 || tab1[index1] <= tab2[index2])) {
            tab[i] = tab1[index1];
            ++index1;
        } else {
            tab[i] = tab2[index2];
            ++index2;
        }
    }
    return tab;
}

int main() {
    int tab1[20];
    int tab2[20];
    int i;
    int nb1, nb2;
    int* tab;

    scanf("%d", &nb1);
    scanf("%d", &nb2);
    for (i = 0; i < nb1; i++) {
        scanf("%d", tab1 + i);
    }
    for (i = 0; i < nb2; i++) {
        scanf("%d", tab2 + i);
    }

    tab = fusion(tab1, nb1, tab2, nb2);
    for (i = 0; i < nb1 + nb2; i++) {
        printf("%d  ", tab[i]);
    }
    printf("\n");
    free(tab);
    return 0;
}
