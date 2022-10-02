#include<iostream>
#include<cstdio>
using namespace std;
int dp[30005],v[30],w[30],n,m;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>v[i]>>w[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=n;j>=v[i];j--)
		{
			dp[j]=max(dp[j],dp[j-v[i]]+v[i]*w[i]);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}
