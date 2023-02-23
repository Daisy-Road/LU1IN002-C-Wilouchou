#include <stdio.h>
#include <stdlib.h>

#define NB_VILLES 5

void affiche_distances(int* villes, int dist[NB_VILLES][NB_VILLES]) {
    printf("km\t");
    for (int i = 0; i < NB_VILLES; i++) {
        printf("%d\t", villes[i]);
    }
    printf("\n"); // Première ligne département
    for (int i = 0; i < NB_VILLES; i++) {
        printf("%d\t", villes[i]); // Colonne département
        for (int j = 0; j < NB_VILLES; j++) {
            (dist[i][j] == 0) ? printf("-\t")
                              : printf("%d\t", dist[i][j]); // Ligne distance
        }
        printf("\n"); // Toutes les distances calculées pour villes[j]
    }
}

int plus_proche(int laville, int villes[], int dist[NB_VILLES][NB_VILLES]) {
    int check = -1;
    for (int i = 0; i < NB_VILLES; i++) {
        if (villes[i] == laville) {
            check = i;
            break;
        }
    }
    if (check == -1) return -1;
    int min = -1;
    int res = -1;
    int current_test;
    for (int i = 0; i < NB_VILLES; i++) {
        current_test = dist[i][check];
        if (current_test == 0) continue;
        if (min == -1) {
            // init
            min = current_test;
            res = 0;
        } else if (min > current_test) {
            min = current_test;
            res = i;
        }
    }
    return res;
}

int main() {
    int villes[NB_VILLES] = {29, 59, 67, 75, 83};

    int distances[NB_VILLES][NB_VILLES] = {{0, 598, 900, 504, 995},
                                           {598, 0, 407, 203, 861},
                                           {900, 407, 0, 397, 621},
                                           {504, 203, 397, 0, 694},
                                           {995, 861, 621, 694, 0}};

    affiche_distances(villes, distances);
    int num;
    printf("Entrez le numéro de la ville pour obtenir le numéro de la plus "
           "proche...\n");
    scanf("%d", &num);
    int res = plus_proche(num, villes, distances);
    if (res != -1)
        printf("La ville la plus proche de %d est %d\n", num, villes[res]);
    else printf("La ville %d n'est pas valide !\n", num);

    return 0;
}
