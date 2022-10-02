#include<stdio.h>
int main()
{
	int n,k;
	double sum=0;
	scanf("%d",&k);
	n=1;
	while(1)
	{
		sum+=1.0/n;
		if(sum>k) break;
		n++;
	}
	printf("%d",n);
	return 0;
}

