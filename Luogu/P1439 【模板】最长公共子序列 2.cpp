#include<iostream>
#include<algorithm>
using namespace std;
int a[100002],b[100002],p[100002],q[100002],dp[100002],n,ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		p[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		q[i]=p[b[i]];
		dp[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(q[j]<q[i])
				dp[i]=max(dp[i],dp[j]+1);
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
