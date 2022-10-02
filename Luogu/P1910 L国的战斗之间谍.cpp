#include<iostream>
using namespace std;
int n,m,x,a[103],b[103],c[103];
int dp[1003][1003];
int main()
{
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i]>>c[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=b[i];j--)
		{
			for(int k=x;k>=c[i];k--)
			{
				dp[j][k]=max(dp[j][k],dp[j-b[i]][k-c[i]]+a[i]);
			}
		}
	}
	cout<<dp[m][x]<<endl;
	return 0;
}
