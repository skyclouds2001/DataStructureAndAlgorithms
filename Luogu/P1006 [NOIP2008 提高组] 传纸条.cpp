#include<iostream>
using namespace std;
int m,n,a[52][52],dp[52][52][102];
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int s=2;s<=m+n;s++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int ii=1;ii<=m;ii++)
			{
				int j=s-i,jj=s-ii;
				if(j<0||jj<0)	break;
				dp[i][ii][s]=max(max(dp[i][ii][s-1],dp[i-1][ii][s-1]),max(dp[i][ii-1][s-1],dp[i-1][ii-1][s-1]))+a[i][j]+a[ii][jj];
				if(i==ii&&j==jj)	dp[i][ii][s]-=a[i][j];
			}
		}
	}
	cout<<dp[m][m][m+n]<<endl;
	return 0;
}
