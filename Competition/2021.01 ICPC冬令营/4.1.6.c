#include<stdio.h>
#include<math.h>
#define PI 3.1415926535
int main()
{
	double s1=0,s2=0,s3=0,a=0;
	while((scanf("%lf",&a))!=EOF)
	{
		s1=(1.0-sqrt(3)+PI/3.0)*a*a;
		s3=(4.0-sqrt(3)-2.0/3.0*PI)*a*a;
		s2=(2.0*sqrt(3)-4.0+PI/3.0)*a*a;
		printf("%.3f %.3f %.3f\n",s1,s2,s3);
	}
	return 0;
 } 
