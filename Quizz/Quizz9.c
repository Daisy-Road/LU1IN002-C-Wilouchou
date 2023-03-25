#include <stdio.h>
#include <stdlib.h>

typedef struct _cellule_t cellule_t;
struct _cellule_t {
    int donnee;
    cellule_t* suivant;
};

cellule_t* cons(int val) {
    cellule_t* cellule = malloc(sizeof(cellule_t));
    cellule->donnee = val;
    cellule->suivant = NULL;
    return cellule;
}

cellule_t* affiche(cellule_t* liste) {
    if (liste == NULL) {
        printf("\n");
        return NULL;
    }
    printf("%d ", liste->donnee);
    return affiche(liste->suivant);
}

int f(cellule_t* liste1, cellule_t* liste2) {

    if ((liste1 == NULL) && (liste2 == NULL)) { return 0; }

    if ((liste1 == NULL) || (liste2 == NULL)) { return 1; }

    return (f(liste1->suivant, liste2->suivant));
}

cellule_t* f2(int val, cellule_t* liste) {
    if (liste == NULL) {
        liste = malloc(sizeof(cellule_t));
        liste->donnee = val;
        liste->suivant = NULL;

    }

    else

    {

        cellule_t* ptr = liste;

        cellule_t* pred = NULL;

        while ((ptr != NULL) && (ptr->donnee <= val)) {
            pred = ptr;
            ptr = ptr->suivant;
        }

        pred->suivant = malloc(sizeof(cellule_t));
        pred->suivant->donnee = val;
        pred->suivant->suivant = ptr;
    }
    return liste;
}

cellule_t* f3(int val, cellule_t* liste) {
    cellule_t* tmp;
    if (liste == NULL) { return NULL; }
    if (liste->donnee == val) {
        tmp = liste->suivant;
        return tmp;
    }
    liste->suivant = f3(val, liste->suivant);
    return liste;
}

int main() {
    cellule_t* liste1;
    liste1 = cons(1);
    liste1->suivant = cons(4);
    liste1->suivant->suivant = cons(12);
    liste1->suivant->suivant->suivant = cons(16);

    cellule_t* liste2;
    liste2 = cons(1);
    liste2->suivant = cons(4);
    liste2->suivant->suivant = cons(12);

    cellule_t* liste3;
    liste3 = cons(1);
    liste3->suivant = cons(4);
    liste3->suivant->suivant = cons(12);
    liste3->suivant->suivant->suivant = cons(17);

    cellule_t* liste;
    liste = cons(12);
    liste->suivant = cons(15);
    liste->suivant->suivant = cons(17);

    affiche(liste1);
    affiche(liste2);
    affiche(liste3);

    printf("%d\n", f(liste1, liste2));
    printf("%d\n", f(liste1, liste3));
    printf("%d\n", f(liste3, liste1));
    printf("%d\n", f(liste3, liste3));

    printf("\n\n");
    affiche(liste);
    f3(15, liste);
    affiche(liste);
    return 0;
}
