#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int s[6],t[6][23],tsum[6],ans;
int dp[1203];
int main()
{
	for(int i=1;i<=4;i++)
		cin>>s[i];
	for(int i=1;i<=4;i++)
		for(int j=1;j<=s[i];j++)
			cin>>t[i][j],tsum[i]+=t[i][j];
	for(int k=1;k<=4;k++)
	{
		for(int i=1;i<=s[k];i++)
		{
			for(int j=tsum[k]/2;j>=t[k][i];j--)
			{
				if(t[k][i]>tsum[k]/2)
				{
					ans+=t[k][i];
					goto OUT;
				}
				else
					dp[j]=max(dp[j],dp[j-t[k][i]]+t[k][i]);
			}	
		}
		ans+=(tsum[k]-dp[tsum[k]/2]);
		OUT:;
		memset(dp,0,sizeof(dp));
	}
	cout<<ans<<endl;
	return 0;
} 
