#include<stdio.h>
int main()
{
	short n=0,i=0;
	int sum=0;
	int f(short);
	scanf("%hd",&n);
	sum=f(n);
	printf("%d",sum);
	return 0;
 } 
int f(short x)
{
	if(x==1)  return 1;
	else return (f(x-1)+1)*2;
}
