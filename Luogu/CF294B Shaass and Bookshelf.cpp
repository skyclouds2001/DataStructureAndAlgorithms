#include<iostream>
#include<cstring>
using namespace std;
int n,t[110],w[110],sum;
long long dp[10000];
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>t[i]>>w[i],sum+=t[i];
	memset(dp,127,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;++i)
		for(int j=sum;j>=t[i];--j)
			dp[j]=min(dp[j],dp[j-t[i]]+w[i]);
	for(int j=sum;j>=0;--j)
		if(sum-j>=dp[j])//竖放的书的厚度之和|j横放的书的厚度之和对应的宽度之和 
		{
			cout<<sum-j;
			break;
		}	
	return 0;
}
