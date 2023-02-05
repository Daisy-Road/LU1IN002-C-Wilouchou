#include <cini.h>
#include <assert.h>

#define WIDTH 1200
#define HEIGHT 720

#define COLOR_BELOW "blue"
#define COLOR_ABOVE "red"
#define COLOR_IN "black"


int position(int a, int b, int x, int y);
void affiche(int a, int b, int width, int height);
void test();

int main() {
    CINI_open_window(WIDTH, HEIGHT, "main");
    affiche(1, 0, WIDTH, HEIGHT);
    CINI_loop();
    return 0;
}

int position(int a, int b, int x, int y) {
    int applied = a*x+b;
    if(y > applied) {
        return -1;
    }
    else if(y < applied) {
        return 1;
    } else {
        return 0;
    }
}

void affiche(int a, int b, int width, int height) {
    int x;
    int y;
    char* color;
    for(x = 0; x < width; x++) {
        for(y = 0; y < height; y++) {
            int result_pos = position(a, b, x, y);
            if(result_pos == -1) {
                color = COLOR_BELOW;
            } else if (result_pos == 1) {
                color = COLOR_ABOVE;
            } else {
                color = COLOR_IN;
            }
            CINI_draw_pixel(x, y, color);
        }
    }
}

void test() {

}
