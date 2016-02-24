#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;
 
  
  c.red = 50;
  c.green = 175;
  c.blue = 100;
  
  clear_screen(s);


  //octant 1
  draw_line( 0, 0, XRES-1, YRES - 75, s, c);
  draw_line( 0, 40, XRES-1, YRES - 35, s, c);
  draw_line( 0, 80, XRES-5, YRES, s, c);
  draw_line( 0, 120, XRES-45, YRES, s, c);

  draw_line( 0, 160, XRES-85, YRES, s, c);
  draw_line( 0, 200, XRES-125, YRES, s, c);
  draw_line( 0, 240, XRES-165, YRES, s, c);

  //octant 2
  draw_line( 0, 0, XRES - 75, YRES-1, s, c); 
  //octant 8
  draw_line( 0, YRES-1, XRES-1, 75, s, c);  
  //octant 7
  draw_line( 0, YRES-1, XRES - 75, 0, s, c);

  c.green = 0;
  c.blue = MAX_COLOR;
  //octant 5
  draw_line( XRES - 1, YRES - 1, 0, 75, s, c);
  //octant 6
  draw_line( XRES - 1, YRES -1, 75, 0, s, c);
  //octant 4
  draw_line( XRES - 1, 0, 0, YRES - 75, s, c);
  //octant 3
  draw_line( XRES - 1, 0, 75, YRES - 1, s, c);
  
  c.blue = 0;
  c.red = MAX_COLOR;
  //y = x, y = -x
  draw_line( 0, 0, XRES - 1, YRES - 1, s, c);
  draw_line( 0, YRES - 1, XRES - 1, 0, s, c);
  
  //horizontal, vertical line
  //draw_line( 0, YRES / 2, XRES - 1, YRES / 2, s, c);
  //draw_line( XRES / 2, 0, XRES / 2, YRES - 1, s, c);
  int x = 0;
  int y = 0;
  while (x < XRES) {
    draw_line(x, 0, x, YRES - 1, s, c);
    x += 40;
  }
  while (y < YRES) {
    draw_line(0, y, XRES - 1, y, s , c);
    y += 40;
  }
  display(s);
  save_extension(s, "lines.png");
}  

