#include <stdio.h>
#include <stdlib.h>

typedef struct _list {
    int value;
    struct _list* next;
} list;

list* cons(int val, list* plist) {
    list* el;
    el = malloc(sizeof(list));
    el->value = val;
    el->next = plist;
    return el;
}

void print(list* l) {
    while (l) {
        printf("%d ", l->value);
        l = l->next;
    }
    printf("\n");
}

list* f(list* liste) {
    list* tmp;
    tmp = liste;
    if (!tmp) return NULL;
    while (tmp) {
        tmp = tmp->next;
    }
    return tmp;
}

list* f2(list* liste) {
    list* tmp;
    tmp = liste;
    if (!tmp) return NULL;
    while (tmp->next) {
        tmp = tmp->next;
    }
    return tmp;
}

typedef struct _element element;

struct _element {
    int v1;
    int v2;
    element* suivant;
};

element* f3(element* liste, int val1, int val2) {
    element* res = NULL;

    while (liste) {
        if ((liste->v1 != val1) || (liste->v2 != val2)) {
            liste = liste->suivant;
        } else {
            res = liste;
            liste = liste->suivant;
        }
    }
    return res;
}

list* f4(int d, list* liste) {
    list* nCell;
    if (!liste) {
        nCell = malloc(sizeof(list));
        nCell->value = d;
        nCell->next = NULL;
        return nCell;
    }
    liste->next = f4(d, liste->next);
    return liste;
}

int main(void) {
    list* ns = NULL;
    ns = cons(17, ns);
    ns = cons(15, ns);
    ns = cons(12, ns);
    f4(15, ns);
    print(ns);
    // printf("%d\n", f(ns)->value);
    return 0;
}
