#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,k;
int x[10003],y[10003];
int dp[10003][2003];
struct STOP{
	int p,l,h;
}s[10003];
bool cmp(STOP &a,STOP &b)
{
	return (a.p<b.p);
}
const int INF=2139062143;
int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;++i)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=0;i<k;++i)
		scanf("%d%d%d",&(s[i].p),&s[i].l,&s[i].h);
	sort(s,s+k,cmp);
	memset(dp,127,sizeof(dp));
	memset(dp,0,sizeof(dp[0]));
	for(int i=1,kk=0;i<=n;++i)
	{
		for(int j=x[i-1]+1;j<=m+x[i-1];++j)
			dp[i][j]=min(dp[i][j-x[i-1]]+1,dp[i-1][j-x[i-1]]+1);
		for(int j=m+1; j<=m+x[i-1]; ++j)
            dp[i][m]=min(dp[i][m],dp[i][j]);
		for(int j=1;j<=m-y[i-1];++j)
			dp[i][j]=min(dp[i][j],dp[i-1][j+y[i-1]]);
		if(s[kk].p==i)
		{
			for(int j=1;j<=s[kk].l;++j)
				dp[i][j]=INF;
			for(int j=s[kk].h;j<=m;++j)
				dp[i][j]=INF;
			++kk;
		}
		/*for(int j=1;j<=m;++j)
			cout<<" i="<<i<<" j="<<j<<" dp[i][j]="<<dp[i][j]<<endl;
			*/
	}
	int ans=INF;
	for(int j=1;j<=m;++j)
		ans=min(ans,dp[n][j]);
	if(ans<INF)
		cout<<1<<endl<<ans<<endl;
	else
	{
		int i=0,j=0,kk=0;
		for(i=n;i>0;--i)
		{
			for(j=m;j>0;--j)
			{
				if(dp[i][j]<INF)
					goto OUT;
			}
		}
		OUT:;
		for(kk=0;kk<k;++kk)
			if(s[kk].p>i)
				break;
		cout<<0<<endl<<kk<<endl;
	}
	return 0;
}
