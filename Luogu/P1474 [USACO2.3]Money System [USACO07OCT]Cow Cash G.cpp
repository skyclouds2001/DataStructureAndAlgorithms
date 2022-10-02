#include<iostream>
#include<algorithm>
using namespace std;
int N,V,v[30];
long long dp[10003];
int main()
{
	cin>>V>>N;
	for(int i=1;i<=V;++i)
		cin>>v[i];
	sort(v+1,v+V+1);
	dp[0]=1;
	for(int i=1;i<=V;++i)
	{
		for(int j=v[i];j<=N;++j)
		{
			dp[j]=dp[j]+dp[j-v[i]];
		}
	}
	cout<<dp[N]<<endl;
	return 0;
}
