#include<iostream>
using namespace std;
int n,v,a[40],b[40],ans=0x0fffffff;
void dfs(int xx,int xa,int xb)
{
	if(ans==0)
		return;
	if(xx>=n)
	{
		if(xa+xb>=v and (xa!=0 or xb!=0) )
			ans=min(ans,max(xa,xb)-min(xa,xb));
	}
	else
	{
		dfs(xx+1,xa+a[xx+1],xb+b[xx+1]);
		dfs(xx+1,xa,xb);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>v;
	for(int i=1;i<=n;++i)
		cin>>a[i]>>b[i];
	dfs(0,0,0);
	cout<<(ans==0x0fffffff?-1:ans)<<endl;
	return 0;
}
