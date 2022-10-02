#include<iostream>
using namespace std;
int n,m,k,r;
int tp[12],tw[12],sw[12];
long long dp1[152],dp2[152];
int main()
{
	cin>>n>>m>>k>>r;
	for(int i=1;i<=n;i++)
		cin>>tp[i];
	for(int i=1;i<=m;i++)
		cin>>tw[i];
	for(int i=1;i<=m;i++)
		cin>>sw[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=r;j>=tw[i];j--)
		{
			dp1[j]=max(dp1[j],dp1[j-tw[i]]+sw[i]);
			//cout<<"dp["<<i<<"]["<<j<<"]="<<dp1[j]<<endl;
		}
	}
	int tmax;
	for(int i=1;i<=r;i++)
	{
		if(dp1[i]>=k)
		{
			tmax=r-i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=tmax;j>=tp[i];j--)
		{
			dp2[j]=max(dp2[j],dp2[j-tp[i]]+1);
			//cout<<"dp["<<i<<"]["<<j<<"]="<<dp2[j]<<endl;
		}
	}
	cout<<dp2[tmax]<<endl;
	return 0;
}
