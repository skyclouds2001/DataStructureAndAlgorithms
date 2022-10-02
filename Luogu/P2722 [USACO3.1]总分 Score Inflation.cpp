#include<iostream>
using namespace std;
int n,m,t[10005],p[10005],dp[10005];
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i]>>t[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=t[i];j<=m;j++)
		{
			dp[j]=max(dp[j],dp[j-t[i]]+p[i]);
		}
	}
	cout<<dp[m]<<endl;
	return 0;
}
