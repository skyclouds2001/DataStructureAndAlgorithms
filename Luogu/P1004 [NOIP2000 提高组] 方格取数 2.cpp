#include<iostream>
using namespace std;
int a[11][11],N,dp[11][11][22];   //dp[][][] i,k,s(walk lenght)
int main()							//i+j=s=k+l
{
	int x,y,n;
	cin>>N;
	while(true)
	{
		cin>>x>>y>>n;
		if(x==0&&y==0&&n==0)
			break;
		a[x][y]=n;
	}
	for(int s=2;s<=N*2;s++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int k=1;k<=N;k++)
			{
				int j=s-i,l=s-k;
				if(l<=0||j<=0)	break;
				dp[i][k][s]=max(max(dp[i][k][s-1],dp[i-1][k][s-1]),max(dp[i][k-1][s-1],dp[i-1][k-1][s-1]))+a[i][j]+a[k][l];
				if(i==k&&j==l)	dp[i][k][s]-=a[i][j];
			}
		}
	}
	cout<<dp[N][N][2*N]<<endl;
	return 0;
}
