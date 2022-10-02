#include<bits/stdc++.h>
using namespace std;
int n,m,w;
int c[10003],d[10003];
int dp[10003],fa[10003];
int find(int x)
{
	return (fa[x]==x)?x:(fa[x]=find(fa[x]));
}
void merge(int x,int y)
{
	fa[find(y)]=find(x);
}
int main()
{
	cin>>n>>m>>w;
	for(int i=1;i<=n;++i)
		scanf("%d%d",&c[i],&d[i]),fa[i]=i;
	for(int i=1,u,v;i<=m;++i)
		scanf("%d%d",&u,&v),merge(u,v);
	for(int i=1,t;i<=n;++i)
		if(fa[i]!=i)
			t=find(i),c[t]+=c[i],d[t]+=d[i],c[i]=0,d[i]=0;
	for(int i=1;i<=n;++i)
		for(int j=w;c[i]!=0&&j>=c[i];--j)
			dp[j]=max(dp[j],dp[j-c[i]]+d[i]);
	cout<<dp[w]<<endl;
	return 0;
}
