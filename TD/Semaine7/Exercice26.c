#include <cini.h>
#include <cini_console.h>
#include <cini_graphic.h>
#include <stdio.h>
#include <string.h>

/* Question 1
 * Représenter un point avec un tableau de 3 éléments
 * n'est pas possible car la couleur n'est pas un
 * nombre, et un tableau ne continent qu'un seul type
 *
 * La structure est le type le plus adapté */

typedef struct _Point {
    int x, y;
    char color[11];
} point;

typedef struct _Rectangle {
    point A;
    point B;
    char color_line[11];
    char background[11];
} rectangle;

int abs(int a) { return (a <= 0) ? -a : a; }

void affiche_rectangles(rectangle r_list[], size_t len,
                        int pause_between_rectangles) {
    CINI_open_window(1280, 720, "main");
    CINI_fill_window("white");
    for (int i = 0; i < len; i++) {
        rectangle r = r_list[i];
        CINI_draw_pixel(r.A.x, r.A.y, r.A.color);
        CINI_draw_pixel(r.B.x, r.B.y, r.B.color);
        CINI_fill_rect(r.A.x, r.B.y, abs(r.B.x - r.A.x), abs(r.B.y - r.A.y),
                       r.background);
        CINI_draw_line(r.A.x, r.A.y, r.B.x, r.A.y, r.color_line);
        CINI_draw_line(r.A.x, r.A.y, r.A.x, r.B.y, r.color_line);
        CINI_draw_line(r.B.x, r.B.y, r.A.x, r.B.y, r.color_line);
        CINI_draw_line(r.B.x, r.B.y, r.B.x, r.A.y, r.color_line);
        (pause_between_rectangles) ? CINI_loop_until_keyup() : 0;
    }
    CINI_loop();
}

int point_dans_rectangle(point p, rectangle r) {
    int between_x = (r.A.x <= p.x && p.x <= r.B.x);
    int between_y = (r.A.y >= p.y && p.y >= r.B.y); // The Y axis is inverted
    return between_x && between_y;
}

int min(int a, int b) { return (a <= b) ? a : b; }

int max(int a, int b) { return (a >= b) ? a : b; }

rectangle intersection_rectangles(rectangle r1, rectangle r2) {
    // Hypothesis: both rectangles must intersect each other
    rectangle res;

    /* A rectangle can be writtent like this
     * Let A(xA, yA) the lower left corner of R,
     * Let B(xB, yB) the upper right corner of R.
     *
     * R = { (x, y) | xA <= x <= xB and yA <= y <= yB }
     *
     * But the y axis is inverted here:
     * Therefore:
     *
     * R = { (x, y) | xA <= x <= xB and yB <= y <= yA }
     *
     * For the intersection, we need to take the least possible
     * values between both sets r1, r2
     * Wich lead to this construction...*/

    // Intersection of the two sets for point A
    res.A.x = max(r1.A.x, r2.A.x); // lower bound
    res.A.y = min(r1.A.y, r2.A.y); // upper bound (y axis is inverted)
    strcpy(res.A.color, "gray");
    // Intersection of the two sets for point B
    res.B.x = min(r1.B.x, r2.B.x); // upper bound
    res.B.y = max(r1.B.y, r2.B.y); // lower bound (y axis is inverted)
    strcpy(res.B.color, "gray");
    strcpy(res.color_line, "gray");
    strcpy(res.background, "gray");
    return res;
}

rectangle* set_up() {
    rectangle* r_list = malloc(3 * sizeof(rectangle));
    char point_color[11];
    char color_line[11];
    char background[11];
    for (int i = 0; i < 2; i++) {
        printf("Setting up rectangle n°%d\n", i + 1);
        printf("Lower left point X: ");
        scanf("%d", &(r_list[i].A.x));
        printf("\n");
        printf("Lower left point Y: ");
        scanf("%d", &(r_list[i].A.y));
        printf("\n");
        printf("Color of this point: ");
        scanf("%s", point_color);
        strcpy(r_list[i].A.color, point_color);
        printf("\n");

        printf("Upper right point X: ");
        scanf("%d", &(r_list[i].B.x));
        printf("\n");
        printf("Upper right point Y: ");
        scanf("%d", &(r_list[i].B.y));
        printf("\n");
        printf("Color of this point: ");
        scanf("%s", point_color);
        strcpy(r_list[i].B.color, point_color);
        printf("\n");

        printf("Line color of this rectangle: ");
        scanf("%s", color_line);
        printf("\n");
        strcpy(r_list[i].color_line, color_line);
        printf("Background color of this rectangle: ");
        scanf("%s", background);
        printf("\n");
        strcpy(r_list[i].background, background);

        printf("Roger that !\n");
    }
    r_list[2] = intersection_rectangles(r_list[0], r_list[1]);
    return r_list;
}

int main(int argv, char** argc) {
    point mon_point;
    mon_point.x = 4;
    mon_point.y = 3;
    strcpy(mon_point.color, "red");

    point A;
    A.x = 100;
    A.y = 200;
    strcpy(A.color, "red");
    point B;
    B.x = 500;
    B.y = 2;
    strcpy(B.color, "red");

    rectangle r1;
    r1.A = A;
    r1.B = B;
    strcpy(r1.color_line, "red");
    strcpy(r1.background, "white");

    rectangle* r_list = set_up();

    affiche_rectangles(r_list, 3, 1);
    free(r_list);
    return 0;
}
