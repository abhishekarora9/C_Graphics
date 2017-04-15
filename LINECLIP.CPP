#include <iostream.h>
#include <conio.h>
#include <graphics.h>


int main ()
{
	clrscr();
	int x1,y1,x2,y2,x3,y3,x4,y4;
	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
	cout<<"Enter coordiantes of end points of the line"<<endl;
	int linex1,liney1,linex2,liney2;
	cin>>linex1>>liney1>>linex2>>liney2;
	int point1arr[4],point2arr[4];

	clrscr();
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode,"");
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x4,y4);
	line(x4,y4,x1,y1);

	int a[4]={1,0,0,1};
	int b[4]={0,0,0,1};
	int c[4]={0,1,0,1};
	int d[4]={0,1,0,0};
	int e[4]={0,1,1,0};
	int f[4]={0,0,1,0};
	int g[4]={1,0,1,0};
	int h[4]={1,0,0,0};
	int i[4]={0,0,0,0};

	if(linex1<x3){
		point1arr[0]=1;
	}

	if(linex1>x2){
		point1arr[1]=1;
	}

	if(liney1>y3){
		point1arr[2]=1;
	}

	if(liney1<y1){
		point1arr[3]=1;
	}

	if(linex2<x3){
		point2arr[0]=1;
	}

	if(linex2>x2){
		point2arr[1]=1;
	}

	if(liney2>y3){
		point2arr[2]=1;
	}

	if(liney2<y1){
		point2arr[3]=1;
	}
	int flag=0;

	for (int k = 0; k < 4; ++k)
	{
		if(point1arr[k]==point2arr[k]);
		else flag=1;
	}
	
	line(linex1,liney1,linex2,liney2);
	
	
	getch();
	closegraph();





return 0;
}