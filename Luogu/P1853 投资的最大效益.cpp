#include<iostream>
using namespace std;
int s,n,d,a[15],b[15];
int w[45],dp[30000];
int main()
{
	cin>>s>>n>>d;
	for(int i=1;i<=d;++i)
	{
		cin>>a[i]>>b[i];
		a[i]/=1000;
	}
	w[1]=s;
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<=d;++i)
		{
			for(int j=a[i];j<=w[k]/1000;++j)
			{
				dp[j]=max(dp[j],dp[j-a[i]]+b[i]);
			}
		}
		w[k+1]=w[k]+dp[w[k]/1000];
	}
	cout<<w[n+1]<<endl;
	return 0;
}
