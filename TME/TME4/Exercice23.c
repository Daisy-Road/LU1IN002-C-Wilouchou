#include <stdio.h>
#include <stdlib.h>

float* init_temp();

float moy_temp(float* temp, int len) {
    float moy = 0.0;
    for (int i = 0; i < len; i++) {
        moy += temp[i];
    }
    return (float)moy / len;
}

int main() {
    float* temp = init_temp();

    for (int i = 0; i < 31; i++) {
        if (i % 5 == 0 && i != 0) { printf("\n"); }
        printf("temp[%d] = %.2f\t", i, temp[i]);
    }
    printf("\n");
    return 0;
}

float* init_temp() {
    float* res = malloc(31 * sizeof(float));
    for (int i = 0; i < 31; i++) {
        res[i] = 0.0;
    }
    return res;
}
