#include<iostream>
#include<cstdio>
using namespace std;
short n,x,use[1005];
int win[1005],lose[1005];
long long dp[1005];
int main()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)
		scanf("%d%d%hd",&lose[i],&win[i],&use[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=x;j>=0;j--)
		{
			if(j>=use[i])
				dp[j]=max(dp[j]+lose[i],dp[j-use[i]]+win[i]);
			else
				dp[j]=dp[j]+lose[i];
		}
	}
	cout<<5*dp[x]<<endl;
	return 0;
}
