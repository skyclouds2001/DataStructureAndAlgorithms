#include<iostream>
#include<cstdio>
using namespace std;
int H,N,w[505],dp[45005];
int main()
{
	cin>>H>>N;
	for(int i=1;i<=N;i++)
		cin>>w[i];
	for(int i=1;i<=N;i++)
	{
		for(int j=H;j>=w[i];j--)
		{
			dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
		}
	}
	cout<<dp[H]<<endl;
	return 0;
}
