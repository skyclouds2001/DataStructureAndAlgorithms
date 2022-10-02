#include<stdio.h>
#include<math.h>
int main()
{
	double a=0,b=0,c=0,p=0,s=0;
	scanf("%lf%lf%lf",&a,&b,&c);
	p=(a+b+c)/2;
	s=sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%.1f",s);
	return 0;
}
