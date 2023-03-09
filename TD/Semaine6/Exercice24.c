#include <stdio.h>

int equals(char* s1, char* s2) {
    int i = 0;
    while (s1[i] != '\0') {
        if (s1[i] != s2[i]) return 0;
        i++;
    }
    return s2[i] == '\0';
}

int equals_recu(char* s1, char* s2) {
    if (s1[0] == '\0') { return (s2[0] == '\0'); }
    if (s1[0] != s2[0]) {
        return 0;
    } else {
        return equals_recu(s1 + 1, s2 + 1);
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: ./Exercice24.out <string1> <string2>\n");
        return 1;
    }
    char* s1 = argv[1];
    char* s2 = argv[2];
    printf("equals(\"%s\", \"%s\") returned %d\n", s1, s2, equals(s1, s2));
    printf("equals_recu(\"%s\", \"%s\") returned %d\n", s1, s2,
           equals_recu(s1, s2));
    return 0;
}
