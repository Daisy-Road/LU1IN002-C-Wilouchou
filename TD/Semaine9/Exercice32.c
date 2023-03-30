#include "TD9Utils.h"
#include <stdio.h>
#include <stdlib.h>

int equals(List* a, List* b) {
    while (a && b) {
        if (a->value != b->value) return 0;
        a = a->next;
        b = b->next;
    }
    return (!a && !b);
}

int included(List* a, List* b) {
    /* Hypothesis: both a and b are sorted */
    while (a && b) {
        if (a->value > b->value) b = b->next;
        // Value of a might be in b, but higher on the list
        else if (a->value < b->value) return 0;
        // Values of b are too high, exiting.
        else {
            // Values matches, so we keep going with the next a...
            a = a->next;
            b = b->next;
        }
    }
    // If all element of a has been check, we return  1
    // Otherwise we return 0 :3
    return !a;
}

int main() {
    List* l1 = generateList(5);
    List* l2 = generateList(5);
    printf("%d\n", equals(l1, l2));
    printf("%d\n", included(l1, l2));
    List* l3 = generateList(3);
    printf("%d\n", equals(l3, l1));
    printf("%d\n", included(l3, l1));
    printf("%d\n", included(l1, l3));
    // Expected output
    //  1
    //  1
    //  0
    //  1
    //  0
    return 0;
}
