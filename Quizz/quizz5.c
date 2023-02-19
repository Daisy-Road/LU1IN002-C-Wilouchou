#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *f(char *str1, char *str2, int longueur) {
    for (int i = 0; i < longueur; i++) {
        *(str2 + i) = *(str1 + longueur - i - 1);
    }
    *(str2 + longueur) = '\0';
    return str2;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <str1> <str2> <longueur>\n", argv[0]);
        return 1;
    }
    printf("%s\n", f(argv[1], argv[2], atoi(argv[3])));
    return 0;
}
