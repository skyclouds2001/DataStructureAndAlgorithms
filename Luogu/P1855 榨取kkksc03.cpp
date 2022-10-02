#include<iostream>
using namespace std;
int N,M,T,m[102],t[102];
int dp[202][202];
int main()
{
	cin>>N>>M>>T;
	for(int i=1;i<=N;i++)
		cin>>m[i]>>t[i];
	for(int i=1;i<=N;i++)
	{
		for(int j=M;j>=m[i];j--)
		{
			for(int k=T;k>=t[i];k--)
			{
				dp[j][k]=max(dp[j][k],dp[j-m[i]][k-t[i]]+1);
			}
		}
	}
	cout<<dp[M][T];
	return 0;
}
