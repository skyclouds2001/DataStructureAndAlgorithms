#include<iostream>
#include<cmath>
using namespace std;
int n,N;
int prime[1002];
long long dp[1002];
int main()
{
	cin>>n;
	prime[0]=2;
	for(int i=3,j;i<=n;i+=2)
	{
		bool flag=true;
		for(j=3;j<=sqrt(i)&&flag;j+=2)
		{
			if(i%j==0)
				flag=false;
		}
		if(flag)
		{
			N++;
			prime[N]=i;
		}
	}
	dp[0]=1;
	for(int i=0;i<=N;i++)
	{
		for(int j=prime[i];j<=n;j++)
		{
			dp[j]=dp[j]+dp[j-prime[i]];
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}
