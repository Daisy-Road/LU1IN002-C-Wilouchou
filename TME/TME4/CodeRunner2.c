#include <stdio.h>

float moy_temp(float* temp, int nbj) {
    float moy = 0.0;
    for (int i = 0; i < nbj; i++) {
        moy += temp[i];
    }
    return (float)moy / nbj;
}

float moy_temp_gel(float* temp, int nbj) {
    float moy = 0.0;
    int gel = 0;
    for (int i = 0; i < nbj; i++) {
        if (temp[i] > 0) {
            moy += temp[i];
            gel++;
        }
    }
    return (gel > 0) ? (float)moy / gel : 1.0;
}

int main() {
    float tab[31];
    float moy_gel;
    int i, nbj;

    scanf("%d", &nbj);
    for (i = 0; i < nbj; i++) {
        scanf("%f", &tab[i]);
    }
    printf("temperature moyenne sur les %d derniers jours : %.3f\n", nbj,
           moy_temp(tab, nbj));
    moy_gel = moy_temp_gel(tab, nbj);
    if (moy_gel != 1.0) {
        printf("temperature moyenne sur les jours de gel : %.2f\n", moy_gel);
    } else {
        printf("Aucune temperature au-dessous de zero.\n");
    }
    return 0;
}
