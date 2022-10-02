#include<iostream>
#include<algorithm>
using namespace std;
int n,p,s;
long long dp[1002];
struct ITEM{
	int w,v;
}item[1002];
bool cmp(ITEM a,ITEM b)
{
	return (a.w<b.w);
}
int main()
{
	cin>>n>>p>>s;
	for(int i=1;i<=n;i++)
		cin>>item[i].w>>item[i].v;
	sort(item+1,item+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=s;j>=item[i].w;j--)
		{
			dp[j]=max(dp[j],dp[j-item[i].w]+item[i].v);
		}
		if(dp[s]>=p)
		{
			cout<<item[i].w<<endl;
			return 0;
		}
	}
	cout<<"No Solution!"<<endl;
	return 0;
}
