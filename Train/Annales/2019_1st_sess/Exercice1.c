#include <stdio.h>
#include <stdlib.h>

int* creer_tab(int len) {
    int* tab = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        tab[i] = i;
    }
    return tab;
}

void deplacer(int i, int t[]) {
    int el = t[i];
    t[i] = t[0];
    for (int j = 0; j < i - 1; j++) {
        t[j] = t[j + 1];
    }
    t[i - 1] = el;
}

void coupe(int c, int t[], int tt[], int len) {
    for (int i = 1; i < c + 1; i++) {
        tt[len - i] = t[c - i];
    }
    for (int i = c; i < len; i++) {
        tt[i - c] = t[i];
    }
}

void affiche_tab(int t[], size_t len) {
    printf("{");
    for (int i = 0; i < len; i++) {
        if (i == len - 1) {
            printf("%d", t[i]);
            break;
        }
        printf("%d, ", t[i]);
    }
    printf("}\n");
}

void intercale(int c, int t[], int tt[], int len) {
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (c + i >= len) {
            tt[j] = t[j];
            j++;
            printf("%d\n", tt[j]);
            continue;
        }
        tt[j] = t[c + i];
        tt[j + 1] = t[i];
        j += 2;
    }
}

int main() {
    int* tab = creer_tab(6);
    affiche_tab(tab, 6);
    deplacer(3, tab);
    affiche_tab(tab, 6);
    int* tt = creer_tab(6);
    int* t = creer_tab(6);
    coupe(3, t, tt, 6);
    affiche_tab(tt, 6);
    int t2[6] = {1, 2, 3, 4, 5, 6};
    intercale(2, t2, tt, 6);
    affiche_tab(tt, 6);
}
