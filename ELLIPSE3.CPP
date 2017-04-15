#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void DrawEllipse (int xc, int yc, int width, int height)
{
    int a2 = width * width;
    int b2 = height * height;
    int fa2 = 4 * a2, fb2 = 4 * b2;
    int x, y, sigma;

    /* first half */
    for (x = 0, y = height, sigma = 2*b2+a2*(1-2*height); b2*x <= a2*y; x++)
    {
        putpixel (xc + x, yc + y,RED);
        putpixel (xc - x, yc + y,RED);
        putpixel (xc + x, yc - y,RED);
        putpixel (xc - x, yc - y,RED);
        if (sigma >= 0)
        {
            sigma += fa2 * (1 - y);
            y--;
        }
        sigma += b2 * ((4 * x) + 6);
    }

    /* second half */
    for (x = width, y = 0, sigma = 2*a2+b2*(1-2*width); a2*y <= b2*x; y++)
    {
        putpixel (xc + x, yc + y,RED);
        putpixel (xc - x, yc + y,RED);
        putpixel (xc + x, yc - y,RED);
        putpixel (xc - x, yc - y,RED);
        if (sigma >= 0)
        {
            sigma += fb2 * (1 - x);
            x--;
        }
        sigma += a2 * ((4 * y) + 6);
    }
}

void main()
{
int gd=DETECT,gm;
int a,b,xc,yc;
float p1,p2;
clrscr();
initgraph(&gd,&gm,"");
scanf("%d%d",&xc,&yc);
scanf("%d%d",&a,&b);

;
DrawEllipse(xc,yc,a,b);
getch();
closegraph();

}