#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int s,n,m,ans;
int a[103][103];
int dp[20003];
int main()
{
	cin>>s>>n>>m;
	for(int i=1,j;i<=s;++i)
		for(j=1;j<=n;++j)
			scanf("%d",&a[j][i]);
	for(int i=1;i<=n;++i)
		sort(a[i]+1,a[i]+1+s);
	for(int i=1;i<=n;++i)
		for(int j=m;j>=0;--j)
			for(int k=1;k<=s;++k)
				if(j>a[i][k]*2)
					dp[j]=max(dp[j],dp[j-a[i][k]*2-1]+k*i);
	cout<<dp[m];
	return 0;
}
