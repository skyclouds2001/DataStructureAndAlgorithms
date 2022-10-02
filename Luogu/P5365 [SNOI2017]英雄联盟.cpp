#include<iostream>
using namespace std;
unsigned long long N,M,K[130],C[130],ans;
unsigned long long dp[245000],all;
int main()
{
	cin>>N>>M;
	for(int i=1;i<=N;++i)
		cin>>K[i];
	for(int i=1;i<=N;++i)
		cin>>C[i],all+=C[i]*K[i];
	dp[0]=1;
	for(int i=1;i<=N;++i)
		for(int j=all;j>0;--j)
			for(int k=1;k<=K[i]&&j>=k*C[i];++k)
				dp[j]=max(dp[j],dp[j-k*C[i]]*k);
	for(int j=0;j<=all;++j)
		if(dp[j]>=M)
		{
			ans=j;	break;
		}
	if(ans==0)	cout<<1;
	else		cout<<ans;
	return 0;
}
