#include<stdio.h>
int main()
{
	unsigned long long sum=0,n=0;
	scanf("%llu",&n);	
	if(n>3)  sum=n*(n-1)/2*(n-2)/3*(n-3)/4;
	printf("%llu",sum);
	return 0;
}
