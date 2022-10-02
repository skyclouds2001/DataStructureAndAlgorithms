#include<iostream>
using namespace std;
int n,w,v[102],p[102],vmin=0x7FFFFFFF,vsum;
long long dp[603][121],ans;
int main()
{
	cin>>n>>w;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i]>>p[i];
		vsum+=v[i];
		vmin=min(vmin,v[i]);
	}
	for(int i=1;i<=n;i++)
		v[i]-=vmin;
	vsum-=n*vmin;
	for(int i=1;i<=n;i++)
	{
		for(int j=vsum;j>=v[i];j--)
		{
			for(int k=n;k>0;k--)
			{
				if(j+k*vmin<=w)
					dp[j][k]=max(dp[j][k],dp[j-v[i]][k-1]+p[i]);
				//cout<<"i= "<<i<<" dp["<<j<<"]["<<k<<"]="<<dp[j][k]<<endl;
			}
		}
	}
	for(int j=0;j<=vsum;j++)
	{
		for(int k=n;k>0;k--)
		{
			ans=max(ans,dp[j][k]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
