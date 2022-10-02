#include<iostream>
using namespace std;
int n,beginlevel,maxlevel,c[53];
bool dp[53][1003];
int main()
{
	cin>>n>>beginlevel>>maxlevel;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dp[0][beginlevel]=true;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=maxlevel;j++)
		{
			if(j>=c[i]&&j<=maxlevel-c[i])
				dp[i][j]=dp[i-1][j-c[i]]||dp[i-1][j+c[i]];
			else if(j>=maxlevel-c[i]&&j>=c[i])
				dp[i][j]=dp[i-1][j-c[i]];
			else if(j<=c[i]&&j<=maxlevel-c[i])
				dp[i][j]=dp[i-1][j+c[i]];
		}
	}
	for(int k=maxlevel;k>=0;k--)
	{
		if(dp[n][k])
		{
			cout<<k<<endl;
			break;
		}
		if(k==0)
			cout<<-1<<endl;
	}
	return 0;
}
