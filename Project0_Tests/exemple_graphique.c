#include <cini.h>
 
int main() {
   
  //CINI_print_string("Test\n");
  //CINI_open_window(250, 100, "Test");
  //CINI_fill_window("white");
  //CINI_draw_disc(125, 50, 38, "red");
  //CINI_draw_string(12, 30, "black", "Cini vous dit bonjour !" );
  CINI_open_window(400, 300, "Test");
  //CINI_fill_window("black");
  CINI_draw_pixel(199, 200, "white");   /* affiche pt coord x=199, y=200*/
  CINI_draw_pixel(200, 200, "white");   /* affiche pt coord x=200, y=200*/
  CINI_draw_pixel(201, 200, "white");   /* affiche pt coord x=201, y=200*/

  CINI_loop();
  return 0;
}
