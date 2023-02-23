#include <stdio.h>

int compteMultDiv(int n1, int n2) {
    int res = 0;
    int i = 1;
    while ((n1 * i) <= n2) {
        if (n2 % (n1 * i) == 0) ++res;
        ++i;
    }
    return res;
}

int main() {
    int n1, n2;

    /* Les deux instructions suivantes permettent de saisir la valeur des
    variables n1, n2 et borne. Vous ne devez pas les modifier. */
    scanf("%d", &n1);
    scanf("%d", &n2), printf("n1 : %d, n2 : %d\n", n1, n2);

    /* Affichage du nombre de diviseurs */
    printf("%d\n", compteMultDiv(n1, n2));
    return 0;
}
