#include<iostream>
#include<cstdio>
using namespace std;
int dp[10005],m,n,a[105];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=a[i];j--)
		{
			dp[j]=dp[j]+dp[j-a[i]];
		} 
	}
	cout<<dp[m]<<endl;
	return 0;
}
