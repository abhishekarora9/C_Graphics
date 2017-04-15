#include <iostream.h>
#include <conio.h>
#include <graphics.h>
const int INSIDE = 0; 
const int LEFT = 1;   
const int RIGHT = 2;  
const int BOTTOM = 4; 
const int TOP = 8;   
 

int x_max = 0;
int y_max = 0;
int x_min = 0;
int y_min = 0;
 

int computeCode(double x, double y)
{
    
    int code = INSIDE;
 
    if (x < x_min)       
        code |= LEFT;
    else if (x > x_max)  
        code |= RIGHT;
    if (y < y_min)       
        code |= BOTTOM;
    else if (y > y_max) 
        code |= TOP;
 
    return code;
}
void cohenSutherlandClip(double x1, double y1,
                         double x2, double y2)
{
    
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
 
    
    int accept = 0;
 
    while (1)
    {
        if ((code1 == 0) && (code2 == 0))
        {
           
            accept = 1;
            break;
        }
        else if (code1 & code2)
        {
            
            break;
        }
        else
        {
           
            int code_out;
            double x, y;
 
            
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;
 
           
            if (code_out & TOP)
            {
                
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            }
            else if (code_out & BOTTOM)
            {
                
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            }
            else if (code_out & RIGHT)
            {
                
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            }
            else if (code_out & LEFT)
            {
                
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }
 
            
            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    if (accept==1)
    {
       
             line(x1,y1,x2,y2);
        
    }
    
}

 int main()
{
    clrscr();
    cout<<"Enter xmin,xmax,ymin,ymax of the rectangle"<<endl;
    cin>>x_min>>x_max>>y_min>>y_max;
    cout<<"Enter x1,y1,x2,y2 of the line "<<endl;
    int a[1000][2];
    cout<<"Enter the number of coordinates"<<endl;
    int n ;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i][0]>>a[i][1];
    }
    clrscr();

    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode,"");
    line(x_min,y_min,x_max,y_min);
    line(x_max,y_min,x_max,y_max);
    line(x_max,y_max,x_min,y_max);
    line(x_min,y_max,x_min,y_min);
    
   for ( i = 0; i < n-1; i++)
    {
    	cohenSutherlandClip(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
    	
    }
    cohenSutherlandClip(a[n-1][0],a[n-1][1],a[0][0],a[0][1]);

    getch();
    closegraph();
 
    
 
    return 0;
}