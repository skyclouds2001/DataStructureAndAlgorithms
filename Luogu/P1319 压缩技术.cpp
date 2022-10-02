#include<stdio.h>
int main()
{
	int n=0,n0=0,n1=0;
	int k=0;
	scanf("%d",&n);
	while(scanf("%d%d",&n0,&n1)!=EOF)
	{
		while(n0>0)
		{
			putchar('0');
			n0--;
			k++;
			if(k%n==0)	putchar('\n');	
		}
		while(n1>0)
		{
			putchar('1');
			n1--;
			k++;
			if(k%n==0)	putchar('\n');
		}
	}
	return 0;
}
