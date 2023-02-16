#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define MIN -10
#define MAX 10

int* init_alea(int min, int max, int length);

int main() {

    int tab[N];
    for (int i = 0; i < N; i++) {
        tab[i] = i + 1;
        printf("tab[%d] = %d\n", i, tab[i]);
    }
    printf("\n=====================\n\n");
    srand(time(NULL));
    int* tab2 = init_alea(MIN, MAX, N);
    for (int i = 0; i < N; i++) {
        printf("tab_alea[%d] = %d\n", i, tab2[i]);
    }
    free(tab2);
    return 0;
}

int* init_alea(int min, int max, int length) {
    /*
     * This works if tab is not already and not mentionned in the function's
     * parameters We could have also used a pointer to an array of int in our
     * parameters and skip the malloc line
     */
    int* tab = malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        tab[i] = rand() % (max - min + 1) + min;
    }
    return tab;
}
