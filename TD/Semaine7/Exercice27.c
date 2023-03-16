#include <stdio.h>
#include <stdlib.h>

#define TAILLE_STOCK 40

typedef struct _Article {
    int ref;
    float price;
    int quantity;
} article;

void augmentation_prix(article* art, float percent) {
    art->price = art->price * (1 + percent / 100);
}

void augmentation_generale(article stock[], size_t stock_size, float percent) {
    for (int i = 0; i < stock_size; i++) {
        augmentation_prix(&stock[i], percent);
    }
}

void print_stock(article stock[], size_t stock_size) {
    for (int i = 0; i < stock_size; i++) {
        printf("-------Article n°%d--------\n", i + 1);
        printf("Reference: %d\n", stock[i].ref);
        printf("Price: $%.2f\n", stock[i].price);
        printf("Quantity: %d\n\n", stock[i].quantity);
    }
}

int validation_references(article stock[], size_t stock_size) {
    for (int i = 0; i < stock_size; i++) {
        for (int j = 0; j < i; j++) {
            if (stock[i].ref == stock[j].ref) return 0;
        }
    }
    return 1;
}

int main() {
    article stock[TAILLE_STOCK] = {
        {152, 10.5, 10}, {432, 24.3, 50}, {153, 10.5, 10}};
    augmentation_generale(stock, TAILLE_STOCK, 10.0);
    print_stock(stock, 2);
    printf("%d\n", validation_references(stock, 3));
    return 0;
}
