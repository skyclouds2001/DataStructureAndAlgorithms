#include<bits/stdc++.h>
using namespace std;
int N,M,n,ans=-1;
int fa[1004];
struct ROAD{
	int x,y,t;
}road[100004];
bool cmp(ROAD a,ROAD b)
{
	return (a.t<b.t);
}
int find(int x)
{
	return (x==fa[x])?x:(fa[x]=find(fa[x]));
}
int main()
{
	cin>>N>>M;
	for(int i=1;i<=N;++i)
		fa[i]=i;
	for(int i=1;i<=M;++i)
		cin>>road[i].x>>road[i].y>>road[i].t;
	sort(road+1,road+M+1,cmp);
	n=N;
	for(int i=1;i<=M;++i)
	{
		int f1=find(road[i].x),f2=find(road[i].y);
		if(f1!=f2)
			--n,fa[f2]=f1;
		if(n==1)
		{
			ans=road[i].t;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
