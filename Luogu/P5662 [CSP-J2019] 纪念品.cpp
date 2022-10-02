#include<bits/stdc++.h>
using namespace std;
int T,N,M;
int P[102][102];
int dp[10002];
int main()
{
	cin>>T>>N>>M;
	for(int i=1;i<=T;++i)
		for(int j=1;j<=N;++j)
			cin>>P[i][j];
	int K=M;
	for(int i=1;i<=T-1;++i)
	{
		memset(dp,0,sizeof(dp));
		for(int j=1;j<=N;++j)
			for(int k=P[i][j];k<=K;++k)
				dp[k]=max(dp[k],dp[k-P[i][j]]+P[i+1][j]-P[i][j]);
		K+=dp[K];
	}
	cout<<K<<endl;
	return 0;
}
