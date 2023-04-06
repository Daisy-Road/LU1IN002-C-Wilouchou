#include "utils.h"

#include <string.h>

/* Nous avons défini un tableau dans la mémoire dont l'indice correspond à la
 * somme des valeurs de notre clé Ensuite, nous récupérons différents
 * dictionnaire en fonction de la clé de chaque élément */

TabHash* createTabH(size_t s) {
    TabHash* th = malloc(sizeof(TabHash));
    th->size = s;
    th->tab = malloc(s * sizeof(Dictionary*));
    return th;
}

int hash(TabHash* th, char* key) {
    int index = 0;
    while (*key)
        index += *key++;
    return index % th->size;
}

void add(TabHash* th, char* key, int value) {
    int index = hash(th, key);
    Dictionary* pD = th->tab[index];

    while (pD) {
        if (strcmp(pD->key, key)) {
            pD->value = value;
            return;
        }
        pD = pD->next;
    }
    pD = malloc(sizeof(Dictionary));
    pD->key = strdup(key);
    pD->value = value;
    pD->next = th->tab[index];
    th->tab[index] = pD;
}

void printTabHash(TabHash* th) {
    for (int i = 0; i < th->size; i++) {
        Dictionary* pD;
        for (pD = th->tab[i]; pD; pD = pD->next) {
            printf("%s : %d\n", pD->key, pD->value);
        }
    }
}

TabHash* freeTabH(TabHash* th) {
    for (int i = 0; i < th->size; i++) {
        Dictionary* pD = th->tab[i];
        while (pD) {
            Dictionary* tmp = pD;
            pD = pD->next;
            free(tmp->key);
            free(tmp);
        }
    }
    free(th->tab);
    free(th);
    return NULL;
}
