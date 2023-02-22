#include <stdio.h>
#include <stdlib.h>

int indiceInsert(int tab[], int el, int nb, int taille) {
    if (nb == taille) { return -1; }
    for (int i = 0; i < nb; i++) {
        if (el < tab[i]) return i;
        if (el == tab[i]) return -1;
    }
    return nb;
}

int insertElt(int tab[], int el, int* nb, int taille) {
    int indice = indiceInsert(tab, el, *nb, taille);
    if (indice == -1) return 0;
    for (int i = *nb + 1; i > indice; i--) {
        tab[i] = tab[i - 1];
    }
    tab[indice] = el;
    ++*nb;
    return 1;
}

// Test

int main(int argc, char** argv) {
    if (argc <= 4) {
        printf("Usage: ./CodeRunner3.out <el> <nb> <taille> <tab>\n");
        return -1;
    }
    int el = atoi(argv[1]);
    int nb = atoi(argv[2]);
    int taille = atoi(argv[3]);
    int tab[taille];
    for (int i = 0; i < nb; i++) {
        tab[i] = atoi(argv[4 + i]);
    }
    printf("Function returned: %d\n", indiceInsert(tab, el, nb, taille));
    insertElt(tab, el, &nb, taille);
    printf("[");
    for (int i = 0; i < nb + 1; i++) {
        printf("%d, ", tab[i]);
    }
    printf("]\n");

    return 0;
}
