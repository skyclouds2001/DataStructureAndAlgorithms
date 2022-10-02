#include<stdio.h>
#include<math.h>
#define PI 3.141592653589793
typedef struct Point{
	double x;
	double y;
}POINT;
int main()
{
	int i=0;
	POINT P[3];
	double a=0,b=0,c=0,p=0,s=0,d=0,l=0;
	while(scanf("%lf%lf%lf%lf%lf%lf",&(P[0].x),&(P[0].y),&(P[1].x),\
	&(P[1].y),&(P[2].x),&(P[2].y))!=EOF)
	{		
		a=sqrt(pow(P[0].x-P[1].x,2.0)+pow(P[0].y-P[1].y,2.0));
		b=sqrt(pow(P[2].x-P[1].x,2.0)+pow(P[2].y-P[1].y,2.0));
		c=sqrt(pow(P[0].x-P[2].x,2.0)+pow(P[0].y-P[2].y,2.0));
		p=(a+b+c)/2.0;
		s=sqrt(p*(p-a)*(p-b)*(p-c));
		d=a*b*c/(2.0*s);
		l=PI*d;
		printf("%.2f\n",l);
	}
	
	return 0;
}
