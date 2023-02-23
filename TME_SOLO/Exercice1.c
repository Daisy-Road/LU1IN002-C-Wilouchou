/* Ce programme doit comparer deux valeurs et afficher celle qui est la plus
 * grande.
 */

#include <stdio.h>

void compare(int a, int b) {
    if (a > b) {
        printf("%d est plus grand que %d\n", a, b);
    } else {
        if (b > a) {
            printf("%d est plus grand que %d\n", b, a);
        } else {
            printf("%d et %d sont egaux\n", a, b);
        }
    }
}

int main() {
    int a, b;

    /* Les deux insctructions suivantes sont correctes,
    elles permettent de saisir la valeur de a et b */
    scanf("%d", &a);
    scanf("%d", &b);

    compare(a, b);
    return 0;
}
