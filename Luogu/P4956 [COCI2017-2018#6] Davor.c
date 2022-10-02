#include<stdio.h>
int main()
{
	int n=0,x=0,k=0,xx=0,kk=0;
	scanf("%d",&n);
	for(x=n/52/7-3;x>0;x--)
	{
		if((n/52/7-x)%3==0&&x<=100)
		{
			k=(n/52/7-x)/3;
			if(x>xx)
			{
				xx=x;	kk=k;
			}
		}
	}
	x=n/52/7-3*k;
	printf("%d\n%d\n",xx,kk);
	return 0;
}
