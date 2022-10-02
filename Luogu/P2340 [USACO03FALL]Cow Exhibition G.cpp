#include<iostream>
#include<cstring>
using namespace std;
int N,s[500],f[500],ans;
int dp[800020];
int main()
{
	cin>>N;
	for(int i=1;i<=N;++i)
		cin>>s[i]>>f[i];	//s[i] i号奶牛的IQ值 
							//f[i] i号奶牛的EQ值 
	memset(dp,-127,sizeof(dp));
	dp[400000]=0;
	for(int i=1;i<=N;++i)
	{		//IQ值作Vp,EQ值作value 
		if(s[i]>=0)
			for(int j=800000;j>=s[i];--j)
				dp[j]=max(dp[j],dp[j-s[i]]+f[i]);
		else
			for(int j=0;j<=800000+s[i];++j)
				dp[j]=max(dp[j],dp[j-s[i]]+f[i]);
	}
	for(int j=400000;j<=800000;++j)
		if(dp[j]>=0)
			ans=max(ans,dp[j]+j-400000);
	cout<<ans;
	return 0;
}
