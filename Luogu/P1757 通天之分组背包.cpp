#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,N;
struct ITEM{
	int a,b,c;
}s[1003];
int dp[1003];
int f[1003];
bool cmp(ITEM x,ITEM y)
{
	return (x.c<y.c);
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;++i)
		scanf("%d%d%d",&(s[i].a),&(s[i].b),&(s[i].c));
	sort(s+1,s+n+1,cmp);
	N=1;	f[1]=s[1].c;
	for(int i=2;i<=n;++i)
	{
		if(s[i-1].c!=s[i].c)
		{
			f[N+1]=s[i].c;
			++N;
		}
	}
	for(int k=1;k<=N;++k)
	{
		for(int j=m;j>=0;--j)
		{
			for(int i=1;i<=n;++i)
			{
				if(s[i].c==f[k]&&j>=s[i].a)
					dp[j]=max(dp[j],dp[j-s[i].a]+s[i].b);
			}
		}
	}
	cout<<dp[m]<<endl;
	return 0;
}
