#include <stdio.h>
#include <stdlib.h>

typedef struct _List {
    int value;
    struct _List* next;
} List;

List* Creer_cellule(int d) {
    List* res = malloc(sizeof(List));
    res->value = d;
    res->next = NULL;
    return res;
}

List* Inserer_tete(int d, List* list) {
    List* cell = Creer_cellule(d);
    cell->next = list;
    return cell;
}

List* Inserer_fin(int d, List* list) {
    if (!list) return Creer_cellule(d);
    List* res = list;
    while (list->next)
        list = list->next;
    list->next = Creer_cellule(d);
    return res;
}

List* Inserer_en_pos(int d, size_t pos, List* list) {
    List* listcpy = list;
    List* cell = Creer_cellule(d);
    List* prev = NULL;
    while (list && pos != 0) {
        prev = list;
        list = list->next;
        pos--;
    }
    if (!prev) {
        cell->next = list;
        return cell;
    }
    cell->next = list;
    prev->next = cell;
    return listcpy;
}

void print(List* list) {
    printf("{");
    while (list) {
        printf("%d", list->value);
        if (!list->next) break;
        printf(", ");
        list = list->next;
    }
    printf("}\n");
}

int main(int argc, char** argv) {
    List* l = NULL;
    l = Inserer_fin(8, l);
    l = Inserer_tete(7, l);
    l = Inserer_tete(6, l);
    l = Inserer_fin(9, l);
    l = Inserer_tete(5, l);
    l = Inserer_tete(4, l);
    l = Inserer_tete(3, l);
    l = Inserer_tete(2, l);
    l = Inserer_tete(1, l);
    l = Inserer_fin(10, l);

    if (argc == 3) { l = Inserer_en_pos(atoi(argv[1]), atoi(argv[2]), l); }

    print(l);

    return 0;
}
