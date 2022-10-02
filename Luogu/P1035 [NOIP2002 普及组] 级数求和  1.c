#include<stdio.h>
int main()
{
	int n,k;
	double sn(int);
	scanf("%d",&k);
	n=1;
	while(1)
	{
		if(sn(n)>k) break;
		n++;
	}
	printf("%d",n);
	return 0;
}
double sn(int x)
{
	if(x==1)  return 1.0;
	else return (sn(x-1)+1.0/x);
}
