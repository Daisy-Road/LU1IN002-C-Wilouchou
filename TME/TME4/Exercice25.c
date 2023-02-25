#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float* gen_tab() {
    float* res = malloc(10 * sizeof(float));
    for (int i = 0; i < 10; i++) {
        res[i] = (rand() % 20);
    }
    return res;
}

void placeElt(float tab[], int i) {
    int elt = tab[i];
    for (int j = i - 1; j >= 0; j--) {
        if (elt < tab[j]) {
            // Décalage à droite
            tab[j + 1] = tab[j];
        } else {
            tab[j + 1] = elt;
            return;
        }
    }
    tab[0] = elt;
}

void print_tab(float tab[], size_t len, int elperline) {
    printf("tab = {");
    for (int i = 0; i < len - 1; i++) {
        if (i != 0 && i % elperline == 0) printf("\n");
        printf("%.2f, ", tab[i]);
    }
    printf("%.2f}\n", tab[len - 1]);
}

int main() {
    srand(time(NULL));
    float* tab = gen_tab();
    for (int i = 1; i < 10; i++) {
        placeElt(tab, i);
        print_tab(tab, 10, 10);
    }
}
