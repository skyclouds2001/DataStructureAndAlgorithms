#include<iostream>
#include<cstdio>
using namespace std;
int v[2003],n,m;
int dp[2003],g[2003];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		scanf("%d",&v[i]);
	dp[0]=1;
	for(int i=1;i<=n;++i)
		for(int j=m;j>=v[i];--j)
			dp[j]+=dp[j-v[i]],dp[j]%=10;
	for(int i=1;i<=n;++i)
	{
		g[0]=1;
		for(int j=1;j<=m;++j)
			g[j]=(j>=v[i])?((dp[j]-g[j-v[i]]+10)%10):(dp[j]%10),cout<<g[j];
		putchar('\n');
	}	
	return 0;
}
