#include<stdio.h>
#include<ctype.h>
#include<math.h>
int main()
{
	short s[30]={0};
	long long sum=0;
	short i=0,j=0,k=0,n=0;
	char t=0;
	while((t=getchar())!=EOF)  /*luoguyong EOF*/
	{
		if(isdigit(t))
		{
			k*=10;
			k+=t-'0';
		}
		else if(isblank(t))
		{
			s[j]=k;
			j++;
			k=0;
		}
	}
	s[j]=k;
	j++;
	n=j;
	if(n==1)  sum=0;
	else
	{
		for(j=0;j<n;j++)  sum+=s[j];
		sum*=(long long)pow(2,(double)n-1.0);
	}
	printf("%lld",sum);
	return 0;
}
