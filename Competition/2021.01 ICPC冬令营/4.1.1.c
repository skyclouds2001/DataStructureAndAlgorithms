#include<stdio.h>
#include<math.h>
#include<string.h>
#define PI 3.1415926
int main()
{
	double s=0,a=0,l1=0,l2=0;
	char m[5]="min",d[5]="deg",ls[5]={'\0'};
	while((scanf("%lf %lf %s",&s,&a,ls))!=EOF)
	{
		if(!strncmp(m,ls,3))
		{
			if(a>=10800)	a-=10800.0;
			a=a*PI/10800.0;
		}
		else if(!strncmp(d,ls,3))
		{
			if(a>=180)	a-=180.0;
			a=a*PI/180.0;
		}
		l1=(s+6440)*sqrt(2*(1-cos(a)));
		l2=(s+6440)*a;
		memset(ls,'\0',5*sizeof(char));
		printf("%lf %lf\n",l2,l1);
	}
	return 0;
 } 
