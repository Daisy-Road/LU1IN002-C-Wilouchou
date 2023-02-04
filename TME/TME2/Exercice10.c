#include <cini.h>

void carre(int length, int x, int y) {
    int i;
    for(i = 0; i < length; i++) {
        CINI_draw_pixel(i+x, y, "blue");  
        CINI_draw_pixel(i+x, y+length, "green"); 
        CINI_draw_pixel(x, i+y, "red");
        CINI_draw_pixel(length+x, i+y, "black");
    }
}

int main() {

    CINI_open_window(500, 500, "main");
    CINI_fill_window("white");
    carre(150, 200, 200);
    CINI_loop();
    return 0;
}
