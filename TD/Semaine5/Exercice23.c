#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 20
#define MAX 50
#define MIN -50

int* random_tab_init(size_t len, int max, int min) {
    /* Create a random table of number between max and min included */
    int* res = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        res[i] = (rand() % (max - min + 1)) + min;
    }
    return res;
}

void print_tab(int* tab, size_t len, int elperline) {
    printf("==================\n\ntab = {");
    for (int i = 0; i < len - 1; i++) {
        if (i != 0 && i % elperline == 0) printf("\n");
        printf("%d, ", tab[i]);
    }
    printf("%d}\n\n==================\n\n", tab[len - 1]);
}

int indice_min(int tab[], int taille) {
    int min = tab[0];
    int res = 0;
    for (int i = 1; i < taille; i++) {
        if (tab[i] < min) {
            min = tab[i];
            res = i;
        }
    }
    return res;
}

int indice_min_pos(int tab[], int taille) {
    int min = -1;
    int res = -1;
    for (int i = 0; i < taille; i++) {
        if (tab[i] >= 0 && (tab[i] < min || min == -1)) {
            min = tab[i];
            res = i;
        }
    }
    return res;
}

int main() {
    srand(time(NULL));
    int* tab = random_tab_init(LEN, MAX, MIN);
    print_tab(tab, LEN, 10);
    int index = indice_min(tab, LEN);
    int index_pos = indice_min_pos(tab, LEN);
    printf("Le plus petit élément du tableau est tab[%d] = %d\n\n", index,
           tab[index]);
    printf("Le plus petit élément positif du tableau est tab[%d] = %d\n\n",
           index_pos, tab[index_pos]);
    free(tab);
    return 0;
}
