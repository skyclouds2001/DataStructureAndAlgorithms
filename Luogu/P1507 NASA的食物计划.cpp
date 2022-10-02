#include<iostream>
using namespace std;
short v[53],w[53],c[53],N,W,V;
int dp[403][403];
int main()
{
	cin>>V>>W>>N;
	for(int i=1;i<=N;i++)
		cin>>v[i]>>w[i]>>c[i];
	for(int i=1;i<=N;i++)
	{
		for(int j=V;j>=v[i];j--)
		{
			for(int k=W;k>=w[i];k--)
			{
				dp[j][k]=max(dp[j][k],dp[j-v[i]][k-w[i]]+c[i]);
			}
		}
	}
	cout<<dp[V][W];
	return 0;
} 
