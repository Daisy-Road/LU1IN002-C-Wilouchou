#include <stdio.h>
#include <stdlib.h>

int nb_chiffres(int nb) {
    int res = 0;
    int power10 = 10;
    while (nb > power10) {
        power10 *= 10;
        res++;
    }
    return res;
}

char* int_to_str(int val) {
    int max = nb_chiffres(val);
    char* res = malloc(max * sizeof(char));
    char c;
    int i = max;
    while (val != 0) {
        c = (val % 10) + 48;
        val /= 10;
        res[i] = c;
        i--;
    }
    return res;
}

int main() {
    char* res = int_to_str(123456789);
    printf("%s\n", res);
    free(res);
    return 0;
}
