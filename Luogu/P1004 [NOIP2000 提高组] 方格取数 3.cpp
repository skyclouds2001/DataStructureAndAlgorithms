#include<iostream>
using namespace std;
int a[11][11],N,dp[22][22];   //dp[][] i,k i+j=k+l
int main()	// ö��i��k��ʱ���������������ô��ǰ��ֵ������һ���׶ε�ֵ��
{			//���������鶼���á�
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
		for(int i=min(s,N);i>=1;i--)
		{
			for(int k=min(s,N);k>=1;k--)
			{
				int j=s-i,l=s-k;
				dp[i][k]=max(max(dp[i][k],dp[i-1][k]),max(dp[i][k-1],dp[i-1][k-1]))+a[i][j]+a[k][l];
				if(i==k&&j==l)	dp[i][k]-=a[i][j];
			}
		}
	}
	cout<<dp[N][N]<<endl;
	return 0;
}
