#include <stdio.h>

int sommeDiviseurs(int n) {
    int s = 0;
    int i;
    for(i=2; i <= n/2; i++) {
        if(n%i==0) {
            s+=i;
        }
    }
    return s+n;
}

int k_parfait(int n, int k) {
    return sommeDiviseurs(n) == k*n;
}

