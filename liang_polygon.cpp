#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <process.h>
float max(float a, float b, float c, float d)
{
    float maxVal1, maxVal2, maxValf;

    if (a > b)
        maxVal1 = a;

    else
        maxVal1 = b;

    if (c > d)
        maxVal2 = c;

    else
        maxVal2 = d;

    maxVal2 > maxVal1 ? maxValf = maxVal2 : maxValf = maxVal1;

    return maxValf;
}

float min(float a, float b, float c, float d)
{
    float minVal1 = 0, minVal2 = 0, minValf = 0;

    if (a < b)
        minVal1 = a;

    else
        minVal1 = b;

    if (c < d)
        minVal2 = c;

    else
        minVal2 = d;

    if (minVal2 < minVal1)
        minValf = minVal2;

    else
        minValf = minVal1;

    return minValf;
}

void makeWindow(int xmin, int ymin, int xmax, int ymax)
{
    setcolor(BLUE);
    line(xmin, ymin, xmax, ymin);
    line(xmin, ymin, xmin, ymax);
    line(xmax, ymax, xmax, ymin);
    line(xmin, ymax, xmax, ymax);
}

void drawLine(int x1, int y1, int x2, int y2)
{
    setcolor(RED);
    line(x1, y1, x2, y2);
}

int liang_barsky_lineclip()

int main()
{
    int xmin = 100, ymin = 100, xmax = 400, ymax = 400;
    /*
cout<<"Enter Coordinates for Window (xmin,ymin,xmax,ymax) :";
cin>>xmin>>ymin>>xmax>>ymax;
*/
    
    cout<<"\nEnter Coordinates for line (x1,y1,x2,y2) :";
cin>>x1>>y1>>x2>>y2;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, " ");
    makeWindow(xmin, ymin, xmax, ymax);
    drawLine(x1, y1, x2, y2);
    
    float p[10], q[10], u[4] = { 0 };

    float u1, u2, i;
    float xClip1, yClip1, xClip2, yClip2;
    float dx = x2 - x1;
    float dy = y2 - y1;
    p[1] = -dx;
    p[2] = dx;
    p[3] = -dy;
    p[4] = dy;

    q[1] = x1 - xmin;
    q[2] = xmax - x1;
    q[3] = y1 - ymin;
    q[4] = ymax - y1;

    u1 = 0.0;
    u2 = 1.0;
    for (i = 1; i <= 4; i++) {
        if (p[i] < 0)
            u[i] = q[i] / p[i];
    }
    u1 = max(u[1], u[2], u[3], u[4]);

    if (u1 < 0)
        u1 = 0;

    u[1] = 1;
    u[2] = 1;
    u[3] = 1;
    u[4] = 1;

    for (i = 1; i <= 4; i++) {
        if (p[i] > 0)
            u[i] = q[i] / p[i];
    }

    u2 = min(u[1], u[2], u[3], u[4]);

    if (u2 > 1)
        u2 = 1;

    if (p[1] == 0) {
        if (q[1] < 0 || q[2] < 0)
            exit(0);
    }
    if (u1 > u2)
        exit(0);

    xClip1 = x1 + u1 * dx;
    yClip1 = y1 + u1 * dy;
    xClip2 = x1 + u2 * dx;
    yClip2 = y1 + u2 * dy;

    setcolor(WHITE);
    line(xClip1, yClip1, xClip2, yClip2);
    getch();
    return 0;
}