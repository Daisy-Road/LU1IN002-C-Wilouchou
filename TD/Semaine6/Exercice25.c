#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 20
#define STEP 3

// Generate a random ordered table
void init_rand_ord_tab(int* tab, int len, int step) {
    int min = 0;
    int max = step;
    for (int i = 0; i < len; i++) {
        tab[i] = (rand() % (max - min + 1)) + min;
        max += step;
        min += step;
    }
}

// Print function of a table
void affiche(int* tab, int len) {
    printf("tab = {");
    for (int i = 0; i < len - 1; i++) {
        printf("%d, ", tab[i]);
    }
    printf("%d};\n", tab[len - 1]);
}

/* Question 1:
 *
 * Indice du milieu: (d+g)/2
 * [g, (d+g)/2-1]
 * [(d+g)/2+1, d]
 *
 * Question 2:
 * Lorsque le g dépasse d
 * Ou lorsqu'ils sont égaux et que la valeur n'est
 * pas la bonne
 *
 * Question 3:
 * d >= g
 *
 * */

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
    if (tab[i] < num) return recherche_recu(tab + i + 1, i, num);
    else return recherche_recu(tab, i, num);
}

int main() {
    srand(time(NULL));
    int tab[LEN];
    int search;
    init_rand_ord_tab(tab, LEN, STEP);
    affiche(tab, LEN);
    printf("What are we looking for ? ");
    scanf("%d", &search);
    printf("\n");
    printf("%d\n", recherche_recu(tab, LEN, search));

    return 0;
}
