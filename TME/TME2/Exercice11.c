#include <stdio.h>
#include <assert.h>

#define POP 10000
//#define PROPORTION(A, B) ((float)A / B) *100 Non autorisé sur coderunner

int jours(int nb_contam, int pop, float prop);
float pourcentage(int nb_contam, int pop, int jours);
void test();

int main() {
    test();
    return 0;
}

int jours(int nb_contam, int pop, float prop) {
    /* Params:
     * nb_contam : nombre contamination journalière par personne
     * pop: population total
     * prop: proprotion de contamination à atteindre en % (0.0 <= x <= 100.0) */
    int infectes = 1;
    int jours = 0;
    while(((float)infectes/pop)*100 <= prop) {
        infectes *= (1+nb_contam);
        jours++;
    }
    return jours;
    
}

float pourcentage(int nb_contam, int pop, int jours) {
     /* Params:
     * nb_contam : nombre contamination journalière par personne
     * pop: population total
     * prop: proprotion de contamination à atteindre en % (0.0 <= x <= 100.0) */
    int infectes = 1;
    int i;
    for(i = 0; i < jours; i++) {
        infectes *= (1+nb_contam);
    }
    float prop = ((float)infectes/pop)*100;
    if(prop >= 100.0) {
        return 100.0;
    } else {
        return prop;
    }
}


void test() {
      assert(jours(5, POP, 100.0) == 6);
      assert(jours(5, POP, 50.0) == 5);
      assert(jours(5, POP, 25.0) == 5);
      assert(jours(5, POP, 10.0) == 4);
      printf("%f\n", pourcentage(5, POP, 2));
      printf("%f\n", pourcentage(5, POP, 3));
      printf("%f\n", pourcentage(5, POP, 4));
      printf("%f\n", pourcentage(5, POP, 5));
      printf("%f\n", pourcentage(5, POP, 6));




}
