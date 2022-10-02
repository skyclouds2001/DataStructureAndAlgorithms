#include<stdio.h>
#include<math.h>
int main()
{
	int n=0,a[100]={0};
	int i=0;
	_Bool f(int);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	for(i=0;i<n;i++)
	{
		if(f(a[i]))	printf("%d ",a[i]);
	}
	return 0;
 } 
_Bool f(int x)
{
	int i=0;
	if(x<=1)	return 0;
	else if(x==2)	return 1;
	else if(x%2==0)	return 0;
	else
	{
		for(i=3;i<=sqrt(x);i+=2)
		{
			if(x%i==0)	return 0;
		}
		return 1;
	}
	return 0;
}
