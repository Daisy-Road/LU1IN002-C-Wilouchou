#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIMEOUT 10

void init_rand_ord_tab(int* tab, int len) {
    int min = 0;
    int max = 5;
    for (int i = 0; i < len; i++) {
        tab[i] = (rand() % (max - min + 1)) + min;
        max += 5;
        min += 5;
    }
}

void affiche(int* tab, int len) {
    printf("tab = {");
    for (int i = 0; i < len - 1; i++) {
        printf("%d, ", tab[i]);
    }
    printf("%d}\n", tab[len - 1]);
}

int recherche(int* tab, int len, int num) {
    int min = 0;
    int max = len;
    int i = len / 2;
    while (min <= max) {
        if (tab[i] == num) return 1;
        if (tab[i] < num) {
            min = i + 1;
        } else {
            max = i - 1;
        }
        i = (max + min) / 2;
    }
    return tab[i] == num;
}

int recherche_recu(int* tab, int len, int num) {
    int i = len / 2;
    if (len == 0) return 0;
    if (tab[i] == num) return 1;
    if (tab[i] < num) return recherche_recu(tab + len / 2 + 1, len / 2, num);
    else return recherche_recu(tab, len / 2 - 1, num);
}

int main() {
    srand(time(NULL));
    int tab[10];
    int search;
    init_rand_ord_tab(tab, 10);
    affiche(tab, 10);
    printf("What are we looking for ? ");
    scanf("%d", &search);
    printf("\n");
    printf("%d\n", recherche_recu(tab, 10, search));

    return 0;
}
