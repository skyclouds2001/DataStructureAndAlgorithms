#include<stdio.h>
int exgcd(int a, int b, int &x, int &y)
{
	if (b==0)
	{
		x=1;	y=0;	return a;
	}
	int t=exgcd(b, a%b, x, y);
	int x0=x, y0=y;
	x=y0; y=x0-(a/b)*y0;
	return t;
}
int GCD(int a,int b)
{
	if(a==0)	return b;
	else	return GCD(b%a,a);
}
int main()
{
	int a=0,b=0,x=0,y=0,d=0;
	while((scanf("%d %d",&a,&b))!=EOF)
	{
		exgcd(a,b,x,y);
		d=GCD(a,b);
		printf("%d %d %d\n",x,y,d);
	}
	return 0;
}
/*
Sample Input
4 6
17 17
Sample Output
-1 1 2
0 1 17
*/
