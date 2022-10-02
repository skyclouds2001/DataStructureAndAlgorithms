#include<cstdio>
#define MAX(a,b) ((a>b)?a:b)
using namespace std;
short T,M,t[101],v[101];
short dp[101][1001];		//dp[i][j]表示前i个物品所花的j长度的时间 
int main()
{
	scanf("%hd %hd",&T,&M);
	for(int k=1;k<=M;k++)
		scanf("%hd %hd",&t[k],&v[k]);
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=T;j++)
		{
			if(t[i]>j)	dp[i][j]=dp[i-1][j];
			else
			{
				dp[i][j]=MAX(dp[i-1][j],dp[i-1][j-t[i]]+v[i]);
			}
		}	
	}
	printf("%hd",dp[M][T]);
	return 0;
}
