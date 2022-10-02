#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int c,d,n,m,k;
int dp[10003],ans=0x0fffffff;
int main()
{
	cin>>c>>d>>n>>m>>k;
	memset(dp,127,sizeof(dp));
	dp[0]=0;
	for(int j=1;j<=n*m;++j)
	{
		if(j>=n)
			dp[j]=min(dp[j-n]+c,dp[j]);
		if(j>=1)
			dp[j]=min(dp[j],dp[j-1]+d);
	}
	for(int j=n*m-k;j<=n*m;++j)
		ans=min(ans,dp[j]);
	cout<<ans<<endl;
	return 0;
}
