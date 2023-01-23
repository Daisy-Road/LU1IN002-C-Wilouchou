#include <assert.h>

int surface(int l, int h) {
    /* Retourne la surface
     * d'un rectangle de longueur l et de hauteur h
     */
    return l * h;
}

int main() {
    assert(surface(4, 6) == 24);
    assert(surface(2, 1) == 2);
    assert(surface(3, 4) == 12);
    assert(surface(10, 0) == 0);
    assert(surface(9, 9) == 81);
    return 0;
}
