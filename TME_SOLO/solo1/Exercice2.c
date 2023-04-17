#include <stdio.h>

float noteFinale(float tp, float td, float c1, float c2, float sc) {
    float note_final = tp + td;
    if (c1 > c2 * (20.0 / 50.0)) note_final = note_final + c1 + c2;
    else note_final = note_final + (c2 * 20.0 / 50.0) + c2;
    return (note_final > sc) ? note_final : sc;
}

int main() {
    float tp, td, c1, c2, sc;

    /* Les 5 instructions suivantes permettent de saisir
    la valeur de tp,  td,  c1,  c2 et sc. Vous ne devez pas les modifier */
    scanf("%f", &tp);
    scanf("%f", &td);
    scanf("%f", &c1);
    scanf("%f", &c2);
    scanf("%f", &sc);
    printf("tp:%.2f, td:%.2f, c1:%.2f, c2:%.2f, sc:%.2f\n", tp, td, c1, c2, sc);

    float note = noteFinale(tp, td, c1, c2, sc);
    if (note > 50) printf("UE validee avec %.2f/100 \n", note);
    else printf("UE non validee avec %.2f/100\n", note);
    return 0;
}
