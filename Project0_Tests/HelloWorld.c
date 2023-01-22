#include <stdio.h>

/*
Format:
%d decimal
%ld long decimal
%u unsigned decimal

%s string
%c character

%f float
%Lf long float
%lf double float
%uf unsigned float

etc.
*/

// test

int FoncAff(const char *aff, int val); // Prototype
float absval(float val);               // Prototype
int sommeIntWhile(int val);            // Prototype
int sommeIntFor(int val);              // Prototype

int global_var = 2019;

int main() {
    int local_var = 5;
    float negative = -5.0;
    float positive = 5.0;
    local_var++;
    char *hw = "Hello World";
    int out = FoncAff(hw, local_var);
    printf("Value of out is %d\n", out);
    printf("Value of abs is %f\n", absval(negative));
    printf("\nsommeIntWhile %d\n", sommeIntWhile(5));
    printf("sommeIntFor %d\n", sommeIntFor(5));
    local_var--;
    return 0;
}

int FoncAff(const char *aff, int val) {
    // print out the string
    return printf("%s\nValue is %d\n", aff, val);
}

float absval(float val) {
    if (val < 0) {
        return -val;
    }
    return val;
}

int sommeIntWhile(int max) {
    int sum = 0;
    while (max--) {
        // Will stop when max = 0
        sum += max;
    }
    return sum;
}

int sommeIntFor(int max) {
    int sum = 0;
    int i;
    for (i = 0; i < max; i++) {
        sum += i;
    }
    return sum;
}
