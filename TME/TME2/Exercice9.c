#include <cini.h>

void diagonale(int x) {
    // Le point de coordonnée (x, x) doit appartenir à la fenêtre ouverte
    int k = 1;
    if(x < 0) {
        k=-1;
        x = -x;
    }
    int i;
    for(i = 0; i < x; i++) {
        CINI_draw_pixel(i, i, "white");
    }
}

int main() {
    CINI_open_window(400, 300, "Main");
    diagonale(200);
    CINI_loop();
    return 0;
}
