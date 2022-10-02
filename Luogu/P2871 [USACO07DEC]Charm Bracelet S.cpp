#include<iostream>
using namespace std;
short N,M,ci[3403],wi[3403];
short dp[12881];
#define MAX(a,b) ((a>b)?(a):(b))
int main()
{
	cin>>N>>M;
	for(int k=1;k<=N;k++)
		cin>>ci[k]>>wi[k];
	for(int i=1;i<=N;i++)
	{
		for(int j=M;j>=1;j--)
		{
			if(ci[i]<=j)
			{
				dp[j]=MAX(dp[j],dp[j-ci[i]]+wi[i]);
			}
		}
	}
	cout<<dp[M];
	return 0;
}
