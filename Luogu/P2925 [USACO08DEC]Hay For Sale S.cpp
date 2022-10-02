#include<iostream>
#include<cstdio>
using namespace std;
int dp[50005],C,H,v[5005];
int main()
{
	cin>>C>>H;
	for(int i=1;i<=H;i++)
		cin>>v[i];
	for(int i=1;i<=H;i++)
	{
		for(int j=C;j>=v[i];j--)
		{
			dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
		}
	}
	cout<<dp[C]<<endl;
	return 0;
}
