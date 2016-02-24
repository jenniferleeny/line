#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

void draw_octant1(int x0, int y0, int x1, int y1, screen s, color c) {
  int x = x0;
  int y = y0;
  int A = y1 - y0;
  int B = x0 - x1;
  int delta = 2*A + B;
  while (x <= x1) {    
    plot(s, c, x, y);
    if (delta > 0) {
      y += 1;
      delta += 2*B;
    }
    x += 1;
    delta += 2*A;
  }  
}

void draw_octant2(int x0, int y0, int x1, int y1, screen s, color c) {
  int x = x0;
  int y = y0;
  int A = y1 - y0;
  int B = x0 - x1;
  int delta = A + 2*B;
  while (y <= y1) {
    plot(s, c, x, y);
    if (delta < 0) {
      x += 1;
      delta += 2*A;
    }
    y += 1;
    delta += 2*B;
  }
}

void draw_octant3(int x1, int y1, int x0, int y0, screen s, color c) {
/*
  int x = x0;
  int y = y0;
  int A = y1 - y0;
  int B = x0 - x1;
  int delta = 2*B - A;
  while (y <= y1) {
  plot(s, c, x, y);
    if (delta < 0) {
    x -= 1;
      delta -= 2*A;
      }
    y += 1;
    delta += 2*B;
    }*/
  int x = x0;
  int y = y0;
  int A = y1 - y0;
  int B = x0 - x1;
  int delta = A - 2*B;
  while (y >= y1) {
    plot(s, c, x, y);
    if (delta > 0) {
      x += 1;
      delta += 2*A;
    }
    y -= 1;
    delta -= 2*B;
  }
}

void draw_octant4(int x1, int y1, int x0, int y0, screen s, color c) {
  int x = x0;
  int y = y0;
  int A = y1 - y0;
  int B = x0 - x1;
  int delta = 2*A - B;
  while (x <= x1) {
    plot(s, c, x, y);
    if (delta < 0) {
      y -= 1;
      delta -= 2*B;
    }
    x += 1;
    delta += 2*A;
  }
}

void draw_octant5(int x1, int y1, int x0, int y0, screen s, color c) {
  int x = x0;
  int y = y0;
  int A = y1 - y0;
  int B = x0 - x1;
  int delta = 2*A + B;
  while (x <= x1) {
    plot(s, c, x, y);
    if (delta > 0) {
      y += 1;
      delta += 2*B;
    }
    x += 1;
    delta += 2*A;
  }
}

void draw_octant6(int x1, int y1, int x0, int y0, screen s, color c) {
  int x = x0;
  int y = y0;
  int A = y1 - y0;
  int B = x0 - x1;
  int delta = A + 2*B;
  while (y <= y1) {
    plot(s, c, x, y);
    if (delta < 0) {
      x += 1;
      delta += 2*A;
    }
    y += 1;
    delta += 2*B;
  }
}

void draw_octant7(int x0, int y0, int x1, int y1, screen s, color c) {
  int x = x0;
  int y = y0;
  int A = y1 - y0;
  int B = x0 - x1;
  int delta = A - 2*B;
  while (y >= y1) {
    plot(s, c, x, y);
    if (delta > 0) {
      x += 1;
      delta += 2*A;
    }
    y -= 1;
    delta -= 2*B;
  }
}

void draw_octant8(int x0, int y0, int x1, int y1, screen s, color c) {
  int x = x0;
  int y = y0;
  int A = y1 - y0;
  int B = x0 - x1;
  int delta = 2*A - B;
  while (x <= x1) {
    plot(s, c, x, y);
    if (delta < 0) {
      y -= 1;
      delta -= 2*B;
    }
    x += 1;
    delta += 2*A;
  }
}


//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int x = x1 - x0;
  int y = y1 - y0;
  //octant 1
  if (x > 0 && y >= 0 && x >= y) {
    draw_octant1(x0, y0, x1, y1, s, c);
  }
  //octant 2
  else if (x >= 0 && y > 0 && y > x) {
    draw_octant2(x0, y0, x1, y1, s, c);
  }
  //octant 8
  else if (x > 0 && y < 0 && abs(x) >= abs(y)) {
    draw_octant8(x0, y0, x1, y1, s, c);
  }
  //octant 7
  else if (x > 0 && y < 0 && abs(y) >= abs(x) ) {
    draw_octant7(x0, y0, x1, y1, s, c);
  }
  //octant 3
  else if (x < 0 && y > 0 && abs(y) >= abs(x)) {
    draw_octant3(x0, y0, x1, y1, s, c);
  }
  //octant 4
  else if (x < 0 && y >= 0 && abs(y) < abs(x)) {
    draw_octant4(x0, y0, x1, y1, s, c);
  }
  //octant 5
  else if (x < 0 && y < 0 && abs(x) > abs(y)) {
    draw_octant5(x0, y0, x1, y1, s, c);
  }
  //octant 6
  else if (x < 0 && y < 0 && abs(y) > abs(x)) {
    draw_octant6(x0, y0, x1, y1, s, c);
  }
}

