#include<iostream>
using namespace std;
const int MAX=20000+4;
int n,m,k,numn,ans,minn;
int fa[MAX],p[MAX],num[MAX],dp[2*MAX];
inline void init(int n)
{
	for(int i=1;i<=n;++i)
		fa[i]=i,p[i]=1;
}
int find(int x)
{
	return (fa[x]==x)?x:(fa[x]=find(fa[x]));
}
inline void merge(int x,int y)
{
	int xx=find(x),yy=find(y);
	if(xx!=yy)
		fa[yy]=xx,p[xx]+=p[yy];		//xx|yy
}
inline int mabs(int x)
{
	return (x>=0)?x:(-x);
}
int main()
{
	cin>>n>>m>>k;
	init(n);
	for(register int i=1,x,y;i<=k;++i)
		cin>>x>>y,merge(x,y);
	for(register int i=1;i<=n;++i)
		if(fa[i]==i)
			num[++numn]=p[i];
	for(register int i=1;i<=numn;++i)
		for(register int j=2*m;j>=num[i];--j)
			dp[j]=max(dp[j],dp[j-num[i]]+num[i]);
	minn=0x0fffffff,ans=0x0fffffff;
	for(register int i=1;i<=2*m;++i)	//0
		if(mabs(dp[i]-m)<minn)
			minn=mabs(dp[i]-m),ans=dp[i];
	if(ans==0x0fffffff)		//<
		cout<<0<<endl;
	else
		cout<<ans<<endl;
	return 0;
}
