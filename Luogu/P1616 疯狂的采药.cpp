#include<iostream>
#include<cstdio>
using namespace std;
int n,t;
short timei[10005],valuei[10005];
long long dp[10000005];
#define MAX(a,b) ((a>b)?(a):(b))
int main()
{
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;i++)	scanf("%hd%hd",&timei[i],&valuei[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=timei[i];j<=t;j++)
		{
			dp[j]=MAX(dp[j],dp[j-timei[i]]+valuei[i]);
		}
	}
	printf("%lld",dp[t]);
	return 0;
}
