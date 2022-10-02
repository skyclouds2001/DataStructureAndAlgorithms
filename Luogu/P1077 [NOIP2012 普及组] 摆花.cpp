#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int m,n,a[103];
long long dp[103];
const int MOD=1000007;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	dp[0]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=m;j>=0;--j)
		{
			for(int k=1;k<=min(j,a[i]);++k)
				dp[j]=(dp[j]+dp[j-k])%MOD;
		}
	}
	cout<<dp[m]<<endl;
	return 0;
}
