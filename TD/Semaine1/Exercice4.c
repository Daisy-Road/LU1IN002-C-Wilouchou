#include <assert.h>

int signeSomme(const int a, const int b);

int main() {
    assert(signeSomme(-1, -1) == -1);
    assert(signeSomme(-1, 1) == 0);
    assert(signeSomme(1, -1) == 0);
    assert(signeSomme(-6, 8) == 1);
    assert(signeSomme(6, -8) == -1);
    assert(signeSomme(-12, 2) == -1);
    assert(signeSomme(12, -2) == 1);
    assert(signeSomme(0, 0) == 0);
    return 0;
}

int signeSomme(const int a, const int b) {
    if (a > -b) {
        return 1;
    } if (a < -b) {
        return -1;
    } else {
        return 0;
    }
}
