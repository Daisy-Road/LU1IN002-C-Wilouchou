#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _List {
    int el;
    struct _List* next;
} List;

void print(List* l);
List* select_rand(List* l, int n);

int main(int argc, char** argv) {
    if (argc < 3 || argc < 3 + atoi(argv[2])) {
        printf("Usage: ./remove_rand.out <size to select> <size of list> [List "
               "of integers]\n");
        return 1;
    }
    srand(time(NULL));
    size_t n = atoi(argv[1]);
    size_t size = atoi(argv[2]);
    List* l = NULL;
    for (int i = 0; i < size; i++) {
        List* new_el = malloc(sizeof(List));
        new_el->el = atoi(argv[3 + i]);
        new_el->next = l;
        l = new_el;
    }
    print(l);
    l = select_rand(l, n);
    print(l);
    return 0;
}

void print(List* l) {
    printf("{");
    while (l) {
        if (!l->next) printf("%d}\n", l->el);
        else printf("%d, ", l->el);
        l = l->next;
    }
}

List* select_rand(List* l, int n) {
    int max = 0;
    List* head = l;
    while (l) {
        max++;
        l = l->next;
    }
    int rm = max - n;
    for (int i = 0; i < rm; i++) {
        l = head;
        int r = rand() % max;
        List* prec = NULL;
        while (r) {
            prec = l;
            l = l->next;
            r--;
        }
        if (!prec) {
            head = l->next;
            free(l);
        } else {
            prec->next = l->next;
            free(l);
        }
        max--;
    }
    return head;
}
