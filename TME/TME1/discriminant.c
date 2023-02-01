#include <stdio.h>
#include <math.h>
#include <assert.h>

int discriminant(int a, int b, int c) {
    return b*b-4*a*c;
}

void afficheRacines(int a, int b, int c) {
    int res_discrim = discriminant(a, b, c);
    if(res_discrim > 0) {
        float root1 = (-b-sqrt(res_discrim))/(2.0*a);
        float root2 = (-b+sqrt(res_discrim))/(2.0*a); 
        printf("Les deux racines sont %f %f\n", root1, root2);
    }
    else if(res_discrim == 0) {
        float root = (-b)/(2.0*a);
        printf("Racine double %f\n", root);
    } else {
        printf("Pas de racines réelles");
    }
}

int main() {
    assert(discriminant(1, 2, 0) == 4);
    assert(discriminant(1, 5, 1) == 21);
    assert(discriminant(1, 2, 1) == 0);
    assert(discriminant(2, 2, 1) == -4);
    afficheRacines(1, 5, 1);
    return 0;
}
