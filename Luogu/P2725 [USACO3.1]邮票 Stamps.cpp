#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int nn,n,a[53],sum;
int dp[2000003];
int main()
{
	cin>>nn>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	memset(dp,127,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;++i)		//ÓÊÆ±ÖÖÊý 
	{
		for(int j=a[i];j<=2000000;++j)
		{
			if(dp[j-a[i]]<=nn)
			{
				dp[j]=min(dp[j-a[i]]+1,dp[j]);
			}
		}
	}
	for(int i=1;i<=2000000;++i)
	{
		if(dp[i]>nn)
		{
			cout<<i-1<<endl;
			break;
		}
	}
	return 0;
}
