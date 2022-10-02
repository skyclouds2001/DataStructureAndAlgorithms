#include<iostream>
#include<cstdio>
using namespace std;
unsigned int dp[10005],V[10005],C[10005],n,v,c;
int main()
{
	cin>>v>>n>>c;
	for(int i=1;i<=n;i++)
		scanf("%u%u",&V[i],&C[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=v;j>=C[i];j--)
		{
			dp[j]=max(dp[j],dp[j-C[i]]+V[i]);
		}
	}
	for(int i=0;i<=c;i++)
	{
		if(dp[i]>=v)	
		{
			cout<<c-i<<endl;
			return 0;
		}
	}
	cout<<"Impossible"<<endl;
	return 0;
} 
