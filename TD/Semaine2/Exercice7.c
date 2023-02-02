#include <stdio.h>
#define MAX 5

int premier(int n) {
    int i;
    if(n == 1) return 0;
    for(i=2; i <= n/2; i++) {
        if (n%i == 0) {
            return 0;
        }
    } 
    return 1;
}

void afficheNombresPremiers(int n_max) {
    int i;
    for(i=1; i <= n_max; i++) {
        premier(i) ? printf("%d, ", i) : 0; 
    }
    printf("\n");
}

int main() {
    printf("liste des nombres premiers <= %d\n", MAX);
    afficheNombresPremiers(MAX);
    return 0;
}

/*Question 2
* Il suffit de modifier la valeur MAX de notre
* directive de préprocesseur define en ligne 2 */
