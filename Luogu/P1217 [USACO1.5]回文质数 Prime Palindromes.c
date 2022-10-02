#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int a=5,b=100000000;
	/*scanf("%d%d",&a,&b);*/
	int i=0;
	short f1(int);
	short f2(int);
	for(i=a;i<=b&&i<=9999999;i++)
	{
		if(f1(i)&&f2(i))  printf("%d\n",i);
	}
	return 0;
}
short f1(int x)
{
	short i=0,n=0;
	short p[20]={0};
	while(x)
	{
		p[i]=x%10;
		x/=10;
		i++;
	}
	n=i;
	for(i=0;i<n/2;i++)
	{
		if(p[i]!=p[n-i-1]) return 0;
	}
	return 1;
}
short f2(int x)
{
	int i;
	if(x!=2&&x%2==0)  return 0;
	else
	{
		for(i=3;i<=sqrt(x);i+=2)
		{
			if(x%i==0)  return 0;
		}
	}
	return 1;
}
