#include<stdio.h>
int main()
{
	double s=0,d=0,k=2;
	int n=0;
	scanf("%lf",&s);
	while(d<s)
	{
		d+=k;
		k*=0.98;
		n++;
	}
	printf("%d",n);
	return 0;
}
