//programmer : dhriti
//code : brehenam's

#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int sign(int x)
{
	if(x>0)
		return 1;
	else if(x<0)
		return -1;
	else
	return 0;
}

void bres(int x1, int y1, int x2, int y2)
{
	int x,y,dx,dy,swap,temp,s1,s2,i,p;

	x=x1;
	y=y1;

	dx=abs(x2-x1);
	dy=abs(y2-y1);
	s1=sign(x2-x1);
	s2=sign(y2-y1);

	swap=0;

	putpixel(x1,y1,WHITE);
	if(dy>dx)
	{
		temp=dx;
		dx=dy;
		dy=temp;
		swap=1;
	}

	p=2*dy-dx;

	printf("| k\t| p\t| x\t| y\t|\n");
	printf("| -\t| %d\t| %d\t| %d\t|\n",p,x,y);
	for(i=0;i<dx;i++)
	{
		putpixel(x,y,WHITE);
		while(p>=0)
		{
			p-=2*dx;
			if(swap==1)
				x+=s1;
			else
				y+=s2;

		}
		p+=2*dy;
		if(swap==1)
			y+=s2;
		else
			x+=s1;
		printf("| %d\t| %d\t| %d\t| %d\t|\n",i,p,x,y);
	}
	putpixel(x2,y2,WHITE);
}

void main()
{
	int x1,y1,x2,y2;
	int gm=DETECT, gd=DETECT;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	//left end coord
	printf("Enter the left end point coordinates,\n");
	printf("x cood :\t");
	scanf("%d",&x1);
	printf("y cood :\t");
	scanf("%d",&y1);
	//right end cood
	printf("Enter the right end coordinates,\n");
	printf("x cood :\t");
	scanf("%d",&x2);
	printf("y cood :\t");
	scanf("%d",&y2);
	//call bres func
	bres(x1,y1,x2,y2);
	getch();
}