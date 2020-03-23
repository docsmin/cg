//Programmer name: Dhriti Amlani
//Code title: table
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>

#define ROUND(a)((int)(a+0.5))

void lineDDA(int x1, int y1, int x2, int y2)
{
	int steps,xinc,yinc,x,y,i,dx,dy,s,xi,yi;

	x=x1;
	y=y1;

	dx=x2-x1;
	dy=y2-y1;

	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);

	xinc=dx/(float)steps;
	yinc=dy/(float)steps;

	putpixel(ROUND(x),ROUND(y),WHITE);


	for(i=0;i<=steps;i++)
	{
		x=x+xinc;
		y=y+yinc;
		putpixel(ROUND(x),ROUND(y),WHITE);
	}
}

int main()
{
	int x1,y1,x2,y2;
	int gm=DETECT, gd=DETECT;
	initgraph(&gd,&gm,"C:\\TC\\BGI");

	//call DDA function
	lineDDA(100,400,500,400);
	lineDDA(100,400,100,150);
	lineDDA(100,150,150,100);


	getch();
	closegraph();
	return 0;
}