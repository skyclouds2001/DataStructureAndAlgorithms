#include<iostream>
#include<cstring>
using namespace std;
int num[205][205],m,n;
long long dp[205][205],ans;
int main()
{
	ios::sync_with_stdio(false);
	memset(num,-0x7f,sizeof(num));
	cin>>m>>n;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			cin>>num[i][j];
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			dp[i][j]=max(max(dp[i-1][j+1],dp[i-1][j-1]),dp[i-1][j])+num[i][j];
	ans=max(max(dp[m][n/2+2],dp[m][n/2+1]),dp[m][n/2]);
	cout<<ans<<endl;
	return 0;
}
