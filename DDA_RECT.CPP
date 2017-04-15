#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
void DDA(int x1,int y1,int x2,int y2){
float dx,length,dy,i,x,y;
dx = abs(x2-x1);
dy = abs(y2-y1);
if(dx>=dy) length = dx;
else length = dy;
dx = dx/length;
dy = dy/length;
x=x1;
y=y1;
i=1;
while(i<=length){
putpixel(x,y,WHITE);
x = x + dx;
y = y + dy;
i++;
}

}
int main (){
int gdriver= DETECT,gmode;

int x1,y1,length,breadth;
cin>>x1>>y1;
cin>>length>>breadth;
clrscr();
initgraph(&gdriver,&gmode,"");
DDA(x1,y1,x1+length,y1);
DDA(x1,y1,x1,y1+breadth);
DDA(x1,y1+breadth,x1+length,y1+breadth);
DDA(x1+length,y1,x1+length,y1-breadth);
getch();
closegraph();
return 0;
}



