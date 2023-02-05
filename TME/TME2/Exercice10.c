#include <cini.h>

#define WIDTH 500
#define HEIGHT 500

void carre(int length, int x, int y);
void carres_remontant(int length, int x, int y);

int main() {

    CINI_open_window(WIDTH, HEIGHT, "main");
    CINI_fill_window("white");
    carres_remontant(150, 200, 200);
    CINI_loop();
    return 0;
}

void carre(int length, int x, int y) {
    int i;
    for(i = 0; i < length; i++) {
        CINI_draw_pixel(i+x, y, "blue");  
        CINI_draw_pixel(i+x, y+length, "green"); 
        CINI_draw_pixel(x, i+y, "red");
        CINI_draw_pixel(length+x, i+y, "black");
    }
}

void carres_remontant(int length, int x, int y) {
    
    int i = 0;
    while(x >= 0 || y >= 0) {
        carre(length, x, y);
        x -= 20;
        y -= 20;
        i++;
    }

}
