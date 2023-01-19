#include <stdio.h>

/* 
Format:
%d decimal
%s string
%c character
%f float
*/

int FoncAff(const char* aff, int val); // Prototype

int main() {
    int test = 5;
    test++;
    char* hw = "Hello World";
    int out = FoncAff(hw, test);
    printf("Value of out is %d\n", out);
    test--;
    return 0;
}

int FoncAff(const char* aff, int val) {
    //print out the string
    return printf("%s\nValue is %d\n", aff, val);
}