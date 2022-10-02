#include<iostream>
using namespace std;
int n,W,v[100003],w[100003],dp[40003],nn;
int main()
{
	cin>>n>>W;
	for(int i=1,a,b,c,t;i<=n;i++)
	{
		cin>>a>>b>>c;
		t=1;
		while(t<=c)
		{
			c=c-t;
			w[nn]=b*t;
			v[nn]=a*t;
			t*=2;
			nn++;
		}
		if(c>0)
		{
			w[nn]=b*c;
			v[nn]=a*c;
			nn++;
		}
	}
	for(int i=0;i<=nn;i++)
	{
		for(int j=W;j>=w[i];j--)
		{
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	cout<<dp[W]<<endl;
	return 0;
}
