#include<iostream>
#include<cstring>
using namespace std;
int n,a,b,c;
int dp[4005];
int main()
{
	memset(dp,-1,sizeof(dp));
	cin>>n>>a>>b>>c;
	dp[0]=0;
	for(int i=1,len;i<=3;++i)
	{
		switch(i)
		{
			case 1:len=a;break;
			case 2:len=b;break;
			case 3:len=c;break;
		}
		for(int j=len;j<=n;++j)
		{
			if(dp[j-len]!=-1)
				dp[j]=max(dp[j],dp[j-len]+1);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}
