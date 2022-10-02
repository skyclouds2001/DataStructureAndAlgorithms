#include<iostream>
using namespace std;
int a[11][11],N,dp[11][11][11][11];
int main()
{
	int x,y,n;
	cin>>N;
	while(true)
	{
		cin>>x>>y>>n;
		if(x==0&&y==0&&n==0)
			break;
		a[x][y]=n;
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			for(int k=1;k<=N;k++)
			{
				for(int l=1;l<=N;l++)
				{
					dp[i][j][k][l]=max(max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1]),max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1]))+a[i][j]+a[k][l];
					if(i==k&&j==l)	dp[i][j][k][l]-=a[i][j];
				}
			}
		}
	}
	cout<<dp[N][N][N][N]<<endl;
	return 0;
}
