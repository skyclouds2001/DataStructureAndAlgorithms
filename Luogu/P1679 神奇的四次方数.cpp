#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int v[20],m,dp[100003],n;
int main()
{
	for(int i=1;i<20;i++)
		v[i]=i*i*i*i;
	cin>>m;
	memset(dp,1000000,sizeof(dp));
	dp[0]=0;
	int n=sqrt(sqrt(m))+1;
	for(int i=1;i<=n;i++)
	{
		for(int j=v[i];j<=m;j++)
		{
			dp[j]=min(dp[j],dp[j-v[i]]+1);
		}
	}
	cout<<dp[m];
	return 0;
}
