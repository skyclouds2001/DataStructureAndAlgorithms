#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,h,c[103],p[103],ans=0x0fffffff;
int dp[60003];
int main()
{
	cin>>n>>h;
	for(int i=1;i<=n;i++)
		cin>>p[i]>>c[i];
	memset(dp,127,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=p[i];j<=60000;j++)
		{
			dp[j]=min(dp[j],dp[j-p[i]]+c[i]);
		}
	}
	for(int j=h;j<=60000;++j)
		ans=min(dp[j],ans);
	cout<<ans<<endl;
	return 0;
}
