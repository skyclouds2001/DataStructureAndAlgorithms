#include<cstdio>
#include<iostream>
using namespace std;
short num[1005][1005],n;
long long dp[1005][1005],k;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			scanf("%hd",&num[i][j]);
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+num[i][j];
		}
	}
	for(int j=1;j<=n;j++)
		k=max(k,dp[n][j]);
	cout<<k<<endl;
	return 0;
}
