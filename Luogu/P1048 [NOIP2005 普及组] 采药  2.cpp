#include<cstdio>
#define MAX(a,b) ((a>b)?a:b)
using namespace std;
short T,M,t[101],v[101];
short dp[1001];
int main()
{
	scanf("%hd %hd",&T,&M);
	for(int k=1;k<=M;k++)
		scanf("%hd %hd",&t[k],&v[k]);
	for(int i=1;i<=M;i++)
	{
		for(int j=T;j>=1;j--)
		{
			if(t[i]<=j)
			{
				dp[j]=MAX(dp[j],dp[j-t[i]]+v[i]);
			}
		}
	}
	printf("%hd",dp[T]);
	return 0;
}
