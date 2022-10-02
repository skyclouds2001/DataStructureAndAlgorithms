#include<bits/stdc++.h>
using namespace std;
int N,M;
int a[400],b[5];
int dp[40][40][40][40];
int main()
{
	cin>>N>>M;
	for(int i=1;i<=N;++i)
		cin>>a[i];
	for(int j=1,t=0;j<=M;++j)
		cin>>t,++b[t];
	dp[0][0][0][0]=a[1];
	for(int i=0;i<=b[1];++i)
	{
		for(int j=0;j<=b[2];++j)
		{
			for(int k=0;k<=b[3];++k)
			{
				for(int l=0;l<=b[4];++l)
				{
					int now=1+i+j*2+k*3+l*4;
					if(i>0)
						dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k][l]+a[now]);
					if(j>0)
						dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j-1][k][l]+a[now]);
					if(k>0)
						dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j][k-1][l]+a[now]);
					if(l>0)
						dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j][k][l-1]+a[now]);
				}
			}
		}
	}
	cout<<dp[b[1]][b[2]][b[3]][b[4]]<<endl;
	return 0;
}
