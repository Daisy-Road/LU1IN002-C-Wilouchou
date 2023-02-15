#include <stdio.h>
#define VAL1 -2
#define VAL2 -7
#define VAL3 -5
#define VAL4 -9


void min_max(int value, int* max, int* min) {
    if(value > *max) {
        *max= value;
        return;
    }
    if(value < *min) {
        *min = value;
        return;
    }
    
}

void stats (int a, int b, int c, int d, int* min, int* max, float* moy) {
    *max = -1; *min = -1; *moy = -1.0;
    int t[4] = {a, b, c, d};
    int sum = 0;
    int tot = 0;
    for(int i=0; i < 4; i++) {
        if(t[i] > 0) {
            min_max(t[i], max, min);
            sum += t[i];
            tot++;
            if(*max == -1) *max = t[i];
            if(*min == -1) *min = t[i];
        }
    }
    if(tot > 0) { *moy = (float)(sum)/tot; } 
    else { *moy = -1; *max = -1; *min = -1; }
}

void afficher_resultat(float moyenne, int min, int max) {
  printf("max = %d, min = %d, moy = %.2f\n",max,min,moyenne);
}

int main() {
  float moy;
  int min, max;
  
  /* vous devrez bien sur modifier les parametres d'appel de la fonction stats une fois cette derniere completee */
  stats(VAL1, VAL2, VAL3, VAL4, &min, &max, &moy);
  
  /* vous devrez bien sur modifier les parametres d'appel de la fonction afficher_resultat */
  afficher_resultat(moy, min, max);
  
  return 0;
}
