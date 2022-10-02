#include<bits/stdc++.h>
using namespace std;
int S,D,M;
int P[12][52];
int dp[500002];
int main()
{
	cin>>S>>D>>M;
	for(int i=1;i<=S;++i)
		for(int j=1;j<=D;++j)
			cin>>P[j][i];
	int K=M;
	for(int i=1;i<=D-1;++i)
	{
		memset(dp,0,sizeof(dp));
		for(int j=1;j<=S;++j)
			for(int k=P[i][j];k<=K;++k)
				dp[k]=max(dp[k],dp[k-P[i][j]]+P[i+1][j]-P[i][j]);
		K+=dp[K];
	}
	cout<<K<<endl;
	return 0;
}
