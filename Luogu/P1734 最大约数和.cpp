#include<iostream>
using namespace std;
int n[1000],m,dp[1004];
int main()
{
	cin>>m;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=i/2;j++)
			if(i%j==0)
				n[i]+=j;
	for(int i=1;i<m;i++)
	{
		for(int j=m;j>=i;j--)
		{
			dp[j]=max(dp[j],dp[j-i]+n[i]);
		}
	}
	cout<<dp[m]<<endl;
	return 0;
}
