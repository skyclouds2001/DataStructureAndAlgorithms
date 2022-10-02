#include<stdio.h>
int main()
{
	int p=0,q=0,a=0,b=0;
	long long s=0;
	int i=0;
	while(1)
	{
		s=0;
		scanf("%d%d",&p,&q);
		if(p<0&&q<0)	break;
		a=p;	b=q;
		while(1)
		{
			for(i=a;i<=b;i++)
			{
				if(i%10)	s+=i%10;
			}
			if(a<10&&b<10)	break;
			if(a<10)	a=10;
			a/=10;	b/=10;
		}
		printf("%lld\n",s);
	}
	return 0;
}
