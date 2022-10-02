#include<stdio.h>
#include<math.h>
#define PI 3.1415926535
#define R 6875.0/2.0
int main()
{
	int x[3]={0},y[3]={0},a[3]={0},b[3]={0};
	double xx=0,yy=0,aa=0,bb=0,s=0;
	char fx=0,fy=0,fa=0,fb=0,ls[100]={'\0'};
	gets(ls);	gets(ls);	gets(ls);
	scanf("%d^%d'%d\" %cL",&x[0],&x[1],&x[2],&fx);
	ls[99]=getchar();
	scanf("and %d^%d'%d\" %cL.",&y[0],&y[1],&y[2],&fy);
	ls[99]=getchar();
	gets(ls);
	scanf("%d^%d'%d\" %cL",&a[0],&a[1],&a[2],&fa);
	ls[99]=getchar();
	scanf("and %d^%d'%d\" %cL.",&b[0],&b[1],&b[2],&fb);
	ls[99]=getchar();
	gets(ls);
	xx=(x[0]/1.0+x[1]/60.0+x[2]/3600.0)*PI/180.0;
	yy=(y[0]/1.0+y[1]/60.0+y[2]/3600.0)*PI/180.0;
	aa=(a[0]/1.0+a[1]/60.0+a[2]/3600.0)*PI/180.0;
	bb=(b[0]/1.0+b[1]/60.0+b[2]/3600.0)*PI/180.0;
	if(fx=='S')	xx*=-1;
	if(fy=='W')	yy*=-1;
	if(fa=='S')	aa*=-1;
	if(fb=='W')	bb*=-1;
	s=R*acos(cos(xx)*cos(aa)*cos(yy-bb)+sin(xx)*sin(aa)); 	
	printf("The distance to the iceberg: %.2f miles.\n",s);
	if(s<100.0)	printf("DANGER!");
	return 0;
}
