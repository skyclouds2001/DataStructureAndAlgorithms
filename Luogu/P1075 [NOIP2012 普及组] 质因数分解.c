#include<stdio.h>
#include<math.h>
int main()
{
	short isprime(int);
	int n=0;
	int p=0,q=0;
	scanf("%d",&n);
	int i;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0&&isprime(i)&&isprime(n/i))
		{
			p=n/i;
			break;
		}
	}
	printf("%d",p);
	return 0;
}
short isprime(int x)    //0=no;1=yes;
{
	short flag;
	int i;
	if(x==1||(x!=2&&x%2==0))
	{
		return 0;
	}
	else if(x==2)
	{
		return 1;
	}
	else
	{
		flag=1;
		for(i=3;i<=sqrt(x);i+=2)
		{
			if(x%i==0)
			{
				flag=0;
				break;
			}
		}
		return flag;
	}	
} 
