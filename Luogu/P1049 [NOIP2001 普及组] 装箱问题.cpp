#include<iostream>
#define MAX(a,b) ((a>b)?a:b)
using namespace std;
int V,n,v[31],dp[20001];
int main()
{
	cin>>V;
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>v[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=V;j>0;j--)
		{
			if(v[i]<=j)
			{
				dp[j]=MAX(dp[j],dp[j-v[i]]+v[i]);
			}
		}
	}
	cout<<(V-dp[V]);
	return 0;
}
