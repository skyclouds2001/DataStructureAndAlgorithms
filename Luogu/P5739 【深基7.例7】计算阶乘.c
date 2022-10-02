#include<stdio.h>
int main()
{
	int f(int);
	int result=0;
	int n=0;
	scanf("%d",&n);
	result=f(n);
	printf("%d",result);
	return 0;
}
int f(int n)
{
	if(n==1)  return 1;
	else  return n*f(n-1);
}
