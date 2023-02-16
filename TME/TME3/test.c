#include <math.h>
#include <stdio.h>

int discriminant(int a, int b, int c) { return b * b - 4 * a * c; }

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

int main() {
    int a, b, c;
    int nb_rac;
    float rac1, rac2;

    printf("Entrez les coefficients a (!= 0) b et c du polynome :\n");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    printf("valeur de delta : %d\n", discriminant(a, b, c));
    nb_rac = racines(a, b, c, &rac1, &rac2);
    if (nb_rac == 2) {
        printf("Le polynome a 2 racines : %.3f et %.3f\n", rac1, rac2);
    }
    if (nb_rac == 1) { printf("Le polynome a 1 racine double : %.3f\n", rac1); }
    if (nb_rac == 0) { printf("Le polynome n'a pas de racine reelle.\n"); }
    return 0;
}
