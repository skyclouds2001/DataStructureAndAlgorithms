#include<iostream>
#include<cstdio>
using namespace std;
short n,m;
int num[105][105];
long long dp[105][105];
int x[4]={0,1,0,-1};
int y[4]={1,0,-1,0};
long long dfs(int i,int j)
{
	if(dp[i][j]!=0)	return dp[i][j];
	long long t=0;
	for(int k=0,dx,dy;k<4;k++)
	{
		dx=i+x[k];	dy=j+y[k];
		if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&num[dx][dy]<num[i][j])	//^^^^
		{
			t=max(t,dfs(dx,dy));
		}
	}
	t++;	//^^^^
	dp[i][j]=t;
	return t;
}
int main()
{
	long long ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&num[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ans=max(ans,dfs(i,j));
		}
	}
	cout<<ans<<endl;
	return 0;
}
