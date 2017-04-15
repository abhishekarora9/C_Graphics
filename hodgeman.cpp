#include <iostream.h>
#include <conio.h>
#include <graphics.h>
 int a[1000][2];
const int INSIDE = 0; 
const int LEFT = 1;   
const int RIGHT = 2;  
const int BOTTOM = 4; 
const int TOP = 8;   
 

int x_max = 0;
int y_max = 0;
int x_min = 0;
int y_min = 0;

int Sutherland_Hodgeman(double x1,double y1,double x2,double y2,int n ){
	int left=0;
	int top=0;
	if(x1==x2){
		left=1;

	}
	if(y1==y2)
		top=1;


	for (int i = 0; i < n-1; ++i)
	{
		if(a[i][0])
	}

	

	return 0;
}
int main()
{
    clrscr();
    cout<<"Enter xmin,xmax,ymin,ymax of the rectangle"<<endl;
    cin>>x_min>>x_max>>y_min>>y_max;
   
    cout<<"Enter the number of coordinates"<<endl;
    int n ;
    cin>>n;
    cout<<"Enter x1,y1,x2,y2 of the line "<<endl;

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

    Sutherland_Hodgeman(x_min,y_min,x_max,y_min,n;
    Sutherland_Hodgeman(x_max,y_min,x_max,y_max,n);
    Sutherland_Hodgeman(x_max,y_max,x_min,y_max,n);
    Sutherland_Hodgeman(x_min,y_max,x_min,y_min,n);
   
   

    getch();
    closegraph();
 
    
 
    return 0;
}