#define ROUND(a)  ((int)(a+0.5))
#define LEFT_EDGE 0x1
#define RIGHT_EDGE 0x2
#define BOTTOM_EDGE 0x4
#define TOP_EDGE 0x8

#define INSIDE(a) (!a)
#define REJECT(a,b) (a&b)
#define ACCEPT(a,b) (!(a|b))

unsigned char encode(wcPt2 pt,dcPt winMin,csPt winMax)
{
	unsigned char code=0x00;
	if(pt.x<winMin.x){
	code=code|LEFT_EDGE;}
	if(pt.x>winMax.x){
	code=code|RIGHT_EDGE;}
	if(pt.y<winMin.y){
	code=code|BOTTOM_EDGE;}
	if(pt.y>winMax.y){
	code=code|TOP_EDGE;
	}



void swapPts(wcPt2*p1,wcPt2*p2)
{

wcPt2=temp;
tmp=*p1;*p1=*p2;*p2=tmp;
}



void swapCodes(unsigned char *c1,unsigned char *c2)
{

unsigned char tmp;
tmp=*c1;*c1=*c2;*c2=tmp;

}

  void clipLine(dcPt winMin,dcPt winMax,wcPt2 p1,wcPt2 p2){


  unsigned car code1,code2;
  int done=FALSE,draw=FALSE;
  float m;

  while(!done){
  code1=encode(p1,winMin,winMax);
  code2=encode(p2,winMin,winMax);
  if(ACCEPT(code1,code2)){

  done =TRUE;
  draw=TRUE;

  }
  else
  if(REJECT(code1,code2)){
  done=TRUE;
  }else{if(INSIDE(code1)){

  swapPts(&p1,&p2);
  swapCodes(&code1,&code2);

  }

  if(p2.x!=p1.x)
	   m=(p2.y-p1.y)/(p2.x-p1.x);
	   if(code1&LEFT_EDGE){
	   p1.y+=(winMin.x-p1.x)*m;
	   p1.x=winMin.x;

	   }
     else
     if(code1&RIGHT_EDGE){
      p1.y+=(winMax.x-p1.x)*m;
	   p1.x=winMax.x;

     }
     else
     if(code1&BOTTOM_EDGE){

     if(p2.x!=p1.x){
     p1.x+=(winMin.y-p1.y)/m;

     p1.y=winMin.y;
     }
     else
     if(code1&TOP_EDGE){
     if(p2.x!=p1.x){
	   p1.x+=(winMax.x-p1.y)*m;
	   p1.y=winMax.x;

     }}
     }
  }
  if(draw)
  lineDDA (ROUND(p1.x),ROUND(p1.y),ROUND(p2.x),ROUND(p2.y))

  }












  }

}