#include<iostream>
using namespace std;
int N,M,day[2003][2003];	//step N | team M
int dp[2003][2003],ans=0x7fffffff;
int main()
{
	ios::sync_with_stdio(false);
	cin>>N>>M;
	for(int j=1;j<=M;++j)
		for(int i=1;i<=N;++i)
			cin>>day[i][j];
	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			dp[i][j]=min(dp[i-1][j],dp[i-1][(j+M-2)%M+1])+day[i][j];
	for(int i=1;i<=M;++i)
		ans=min(ans,dp[N][i]);
	cout<<ans<<endl;
	return 0;
}
