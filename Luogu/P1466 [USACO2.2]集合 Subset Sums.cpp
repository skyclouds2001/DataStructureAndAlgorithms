#include<iostream>
using namespace std;
int n,sumh;
long long dp[42][800];
int main()
{
	cin>>n;
	dp[0][0]=1;
	sumh=n*(n+1)/2;
	if(sumh%2==1)
		cout<<0;
	else
	{
		sumh/=2;
		for(int i=1;i<=n;i++)
		{
			for(int j=sumh;j>=0;j--)
			{
				if(j>=i)
					dp[i][j]=dp[i-1][j]+dp[i-1][j-i];
				else
					dp[i][j]=dp[i-1][j];
				//cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
			}
		}
		cout<<dp[n][sumh]/2;
	}
	return 0;
}
