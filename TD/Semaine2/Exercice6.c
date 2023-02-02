#include <assert.h>

int somme_carres(int m, int n) {
    int i = m;
    int s = 0;
    while (i<=n) {
        s += i*i;
        i++;
    }
    return s;
}

int somme_carres_for(int m, int n) {
    int i;
    int s = 0;
    for(i=m; i<=n; i++) {
        s += i*i;
    }
    return s;
}

int main() {
    assert(somme_carres(1, 5) == 55);
    assert(somme_carres(1, 5) == 55);
    assert(somme_carres(2, 5) == 54);
    assert(somme_carres(3, 5) == 50);
    assert(somme_carres(4, 5) == 41);
    assert(somme_carres(5, 5) == 25);
    assert(somme_carres(3, 6) == 86);
    assert(somme_carres(-4, 0) == 30);
    assert(somme_carres(0, 4) == 30);
    assert(somme_carres_for(1, 5) == 55);
    assert(somme_carres_for(1, 5) == 55);
    assert(somme_carres_for(2, 5) == 54);
    assert(somme_carres_for(3, 5) == 50);
    assert(somme_carres_for(4, 5) == 41);
    assert(somme_carres_for(5, 5) == 25);
    assert(somme_carres_for(3, 6) == 86);
    assert(somme_carres_for(-4, 0) == 30);
    assert(somme_carres_for(0, 4) == 30);
    return 0;
}
