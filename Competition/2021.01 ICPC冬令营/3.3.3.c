#include<stdio.h>
long long pxy[2][100]={0};
int main()
{
	int n=0;
	int i=0;
	while((scanf("%d",&n))!=EOF)
	{
		for(i=0;i<n;i++)	scanf("%lld%lld",&pxy[0][i],&pxy[1][i]);
		printf("%d ",n);
		for(i=0;i<n-1;i++)
			printf("%lld %lld ",(pxy[0][i]+pxy[0][i+1])/2,(pxy[1][i]+pxy[1][i+1])/2);
		printf("%lld %lld\n",(pxy[0][0]+pxy[0][n-1])/2,(pxy[1][0]+pxy[1][n-1])/2);
	}
	return 0;
}
