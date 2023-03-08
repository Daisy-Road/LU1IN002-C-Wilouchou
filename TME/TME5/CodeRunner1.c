#include <stdio.h>

int compte_mots(char* s) {
    if (s[0] == '\0') return 0;
    int count = (s[0] == ' ') ? 0 : 1;
    int i = 0;
    while (s[i + 1] != '\0') {
        if (s[i] == ' ' && s[i + 1] != ' ') { count++; }
        i++;
    }
    return count;
}

int main() {
    char* s = "";
    printf("%d\n", compte_mots(s));
    return 0;
}
