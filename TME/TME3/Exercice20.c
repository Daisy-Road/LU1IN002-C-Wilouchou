#include <math.h>
#include <stdio.h>

/* Vous devrez bien sûr modifier les  parametres et valeur de retour des
 * fonctions nb_racines, nb_racines_delta et racines */
/* Les declarations actuelles permettent de compiler et d'executer le programme
 */

/* Dans la fonction affiche_racines, vous devrez compléter l'appel à la fonction
 * racines */

int discriminant(int a, int b, int c) { return b * b - 4 * a * c; }

int nb_racines(int a, int b, int c) {
    int delta = discriminant(a, b, c);
    if (delta < 0) return 0;
    if (delta > 0) return 2;
    else return 1;
}

int nb_racines_delta(int a, int b, int c, int* store_discrim) {
    *store_discrim = discriminant(a, b, c);
    if (*store_discrim < 0) return 0;
    if (*store_discrim > 0) return 2;
    else return 1;
}

int racines(int a, int b, int c, float* x1, float* x2) {
    int delta = 0;
    int nb_racines = nb_racines_delta(a, b, c, &delta);
    if (nb_racines > 0) {
        *x1 = (float)(-b + sqrt(delta)) / (2 * a);
        *x2 = (float)(-b - sqrt(delta)) / (2 * a);
    }
    return nb_racines;
}

void affiche_polynome(int a, int b, int c) {
    /* hypothese : a != 0
      affiche le polynome sous la forme a*x*x + b*x + c
      n'affiche pas les monomes dont le coefficient est nul */
    if (a == 1) {
        printf("Polynome : x*x");
    } else {
        if (a == -1) {
            printf("Polynome : - x*x");
        } else {
            printf("Polynome : %d x*x", a);
        }
    }
    if (b != 0) {
        if (b > 0) {
            if (b == 1) {
                printf(" + x");
            } else {
                printf(" + %d x", b);
            }
        } else {
            if (b == -1) {
                printf(" - x");
            } else {
                printf(" - %d x", -1 * b);
            }
        }
    }
    if (c != 0) {
        if (c > 0) {
            printf(" + %d", c);
        } else {
            printf(" - %d", -1 * c);
        }
    }
    printf("\n");
}

void affiche_racines(int a, int b, int c) {
    float rac1 = 0.0, rac2 = 0.0;
    int nb_rac;

    nb_rac = racines(a, b, c, &rac1, &rac2);
    if (nb_rac == 2) {
        printf("Le polynome a 2 racines : %.3f et %.3f\n", rac1, rac2);
    }
    if (nb_rac == 1) { printf("Le polynome a 1 racine double : %.3f\n", rac1); }
    if (nb_rac == 0) { printf("Le polynome n'a pas de racine reelle.\n"); }
}

int main() {
    int a, b, c;

    /*  1 racine double : -0,5 */
    a = 4;
    b = 4;
    c = 1;
    affiche_polynome(a, b, c);
    affiche_racines(a, b, c);
    printf("\n");

    /*  2 racines  : -0,191 et -1,309 */
    a = 4;
    b = 6;
    c = 1;
    affiche_polynome(a, b, c);
    affiche_racines(a, b, c);
    printf("\n");

    /* Que des coefficients negatifs, pas de racine */
    a = -7;
    b = -5;
    c = -1;
    affiche_polynome(a, b, c);
    affiche_racines(a, b, c);
    printf("\n");

    return 0;
}
