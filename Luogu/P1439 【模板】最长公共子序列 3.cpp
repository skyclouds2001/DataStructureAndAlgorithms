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
	ans=1;
	dp[1]=q[1];
	for(int i=2;i<=n;i++)
	{
		if(q[i]>=dp[ans])	//== is impossible
		{
			++ans;
			dp[ans]=q[i];
		}
		else
		{
			dp[lower_bound(dp+1,dp+ans+1,q[i])-dp]=q[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
