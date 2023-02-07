#include <cini.h>
#include <math.h>

#define WIDTH 1200
#define HEIGHT 700
#define EPSILON 1

void triangles(int width, int height, float epsilon);

int main() {
    CINI_open_window(WIDTH, HEIGHT, "main");
    CINI_fill_window("white");
    triangles(WIDTH, HEIGHT, EPSILON);
    CINI_loop();
    return 0;
}

void triangles(int width, int height, float epsilon) {
    int xA = 0; int yA = height-1; int prevxA = xA; int prevyA = yA;
    int xB = width-1; int yB = height-1; int prevxB = xB; int prevyB = yB;
    int xC = width/2; int yC = 0; int prevxC = xC; int prevyC = yC;
    while((float)sqrt((xA-xB)*(xA-xB) + (yA-yB)*(yA-yB)) > epsilon) {
        CINI_draw_line(xA, yA, xB, yB, "red");
        CINI_draw_line(xA, yA, xC, yC, "blue");
        CINI_draw_line(xB, yB, xC, yC, "green");
        xA = (prevxB+9*xA)/10; yA = (prevyB+9*yA)/10;
        xB = (prevxC+9*xB)/10; yB = (prevyC+9*yB)/10;
        xC = (prevxA+9*xC)/10; yC = (prevyA+9*yC)/10;
        prevxA = xA; prevyA = yA;
        prevxB = xB; prevyB = yB;
        prevxC = xC; prevyC = yC;
        CINI_loop_until_keyup();
    }
    CINI_print_string("Done ! Press Escape to exit\n");
}
