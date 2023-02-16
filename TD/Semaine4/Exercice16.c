#include <stdio.h>

void afficheTab(float tab[], int len, int p) {
    // p raison de l'affichage
    for (int i = 0; i < len; i++) {
        if (i % p == 0 && i != 0) printf("\n");
        printf("tab[%d] = %.2f\t", i, tab[i]);
    }
    printf("\n");
}

void echange(float tab[], int i, int j) {
    float tmp = tab[i];
    tab[i] = tab[j];
    tab[j] = tmp;
}

int main() {
    float tab[5] = {1.2, 1.5, 7.8, 5.4, 9.0};
    afficheTab(tab, 5, 2);
    echange(tab, 2, 3);
    afficheTab(tab, 5, 2);
    return 0;
}
