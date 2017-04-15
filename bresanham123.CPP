#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
void main()
{
    int x, y, x1, y1, x2, y2, dx, dy, p, twodydx, twody;
    cout << "enter x1,y1" << endl;
    cin >> x1 >> y1;
    cout << "enter x2,y2" << endl;
    cin >> x2 >> y2;
    clrscr();
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    dx = x2 - x1;
    dy = y2 - y1;
    if (dx == 0) {
        if (y2 < y1) {
            int temp;
            temp = y1;
            y1 = y2;
            y2 = temp;
        }
        x = x1;
        y = y1;
        while (y < y2) {
            putpixel(x, y, 100);
            y++;
        }
    }
    if (dy == 0) {
        if (x2 < x1) {
            int temp;
            temp = x1;
            x1 = x2;
            x2 = temp;
        }
        x = x1;
        y = y1;
        while (x < x2) {
            putpixel(x, y, 100);
            x++;
        }
    }
    if (dx > 0 && dy > 0 || dy < 0 && dx < 0) {
        if (x1 > x2 && y1 > y2) {
            int temp1, temp2;
            temp1 = x1;
            x1 = x2;
            x2 = temp1;
            temp2 = y1;
            y1 = y2;
            y2 = temp2;
        }
        if (dx >= dy) {
            dx = abs(dx);
            dy = abs(dy);
            p = 2 * dy - dx;
            twodydx = 2 * (dy - dx);
            twody = 2 * dy;
            x = x1;
            y = y1;
            putpixel(x, y, CYAN);
            while (x < x2) {
                x++;
                if (p < 0) {
                    p = p + twody;
                }
                else {
                    y++;
                    p = p + twodydx;
                }
                putpixel(x, y, 100);
            }
        }
        else {
            dx = abs(dx);
            dy = abs(dy);
            p = 2 * dx - dy;
            twodydx = 2 * (dx - dy);
            twody = 2 * dx;

            x = x1;
            y = y1;

            putpixel(x, y, CYAN);
            while (y < y2) {
                y++;
                if (p < 0) {
                    p = p + twody;
                }
                else {
                    x++;
                    p = p + twodydx;
                }
                putpixel(x, y, 100);
            }
        }
    }
    else {
        if (dx < 0) {
            x = x1;
            y = y1;
            putpixel(x, y, BLUE);
            while (x > x2) {
                x--;
                if (p < 0) {
                    p = p + twody;
                }
                else {
                    y++;
                    p = p + twodydx;
                }
                putpixel(x, y, CYAN);
            }
        }
        else {
            x = x1;
            y = y1;
            putpixel(x, y, CYAN);
            while (y > y2) {
                x++;
                if (p < 0) {
                    p = p + twody;
                }
                else {
                    p = p + twodydx;
                    y--;
                }
                putpixel(x, y, BLUE);
            }
        }
    }

    getch();
}
