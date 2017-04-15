#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <iostream.h>
void mod_Bresenham(int x0, int y0, int x1, int y1)
{
    int theRaster[44][44];
    int dx, dy;
    int stepx, stepy;
    dx = x1 - x0;
    dy = y1 - y0;
    if (dy < 0) {
        dy = -dy;
        stepy = -1;
    }
    else {
        stepy = 1;
    }
    if (dx < 0) {
        dx = -dx;
        stepx = -1;
    }
    else {
        stepx = 1;
    }
    dy <<= 1; 
    if ((0 <= x0) && (x0 < RDim) && (0 <= y0) && (y0 < RDim))
        theRaster[x0][y0] = 1;
    16 if (dx > dy)
    {
        int fraction = dy - (dx >> 1);
        while (x0 != x1) {
            x0 += stepx;
            if (fraction >= 0) {
                y0 += stepy;
                fraction -= dx;
            }
            fraction += dy;
            if ((0 <= x0) && (x0 < RDim) && (0 <= y0) && (y0 < RDim))
                theRaster[x0][y0] = 1;
        }
    }
    else
    {
        int fraction = dx - (dy >> 1);
        while (y0 != y1) {
            if (fraction >= 0) {
                17 x0 += stepx;
                fraction -= dy;
            }
            y0 += stepy;
            fraction += dx;
            if ((0 <= x0) && (x0 < RDim) && (0 <= y0) && (y0 < RDim))
                theRaster[x0][y0] = 1;
        }
    }
void main() {
  int x1, x2, y1, y2, i, e, x, y, dx, dy;
  int gdriver = DETECT, gmode;
  initgraph(&gdriver, &gmode,"");
  cout <<"Enter co - ordinates of point 1 : ";
  cin >> x1 >> y1;
  cout <<"Enter co - ordinates of point 2 ";
  cin >> x2 >> y2;

  dx = abs(x2 - x1);
  dy = abs(y2 - y1);
  long long int count =0;
  mod_Bresenham(x1,y1,x2,y2);
  
  
  /*


  x = x1;
  y = y1;

  e = 2 * dy - dx;
  i = 1;
  if((y2-y1)/(x2-x1)<0){
    do {
    putpixel(x, y, CYAN);
    while (e >= 0) {
      y++;
      e = e -2 * dx;
      putpixel(x, y, CYAN);
      count++;
    }
    x++;
    e = e + 2 * dy;
    i++;
  } while (i <= dx&& count<10000);

  }
  else {
  do {
    putpixel(x, y, CYAN);
    while (e >= 0) {
      y++;
      e = e -2 * dx;
      putpixel(x, y, CYAN);
      count++;
    }
    x++;
    e = e + 2 * dy;
    i++;
  } while (i <= dx&& count<10000);
}
*/
  getch();
  closegraph();
}