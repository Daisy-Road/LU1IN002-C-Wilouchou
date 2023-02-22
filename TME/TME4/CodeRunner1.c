#include <stdio.h>

void conversion(int* start, float* res, int len) {
    for (int i = 0; i < len; i++) {
        res[i] = ((float)start[i] - 32.0) * (5.0 / 9.0);
    }
}

int main() {
    int tabF[31];
    float tabC[31];
    int i, nb;

    scanf("%d", &nb);
    for (i = 0; i < nb; i++) {
        scanf("%d", &tabF[i]);
    }

    conversion(tabF, tabC, 31);
    for (i = 0; i < nb; i++) {
        printf("%.1f  ", tabC[i]);
    }
    printf("\n");
    return 0;
}
