#include<stdio.h>
#include<math.h>
int main()
{
	int s=0,n=0,i=0;
	double p=0,pp=0;
	int k=0;
	scanf("%d",&s);
	for(k=0;k<s;k++)
	{
		scanf("%d%lf%d",&n,&p,&i);
		pp=p*pow(1-p,(double)i-1)/(1-pow(1-p,(double)n));
		printf("%.4f\n",pp);
	}	
	return 0;
}
