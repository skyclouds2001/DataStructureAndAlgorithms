#include<iostream>
using namespace std;
int n,m,fa[1004],ans;
int find(int x)
{
	return (x==fa[x])?x:(fa[x]=find(fa[x]));
}
int main()
{
	while(cin>>n>>m)
	{
		if(n==0)
			break;
		for(int i=1;i<=n;++i)
			fa[i]=i;
		ans=0;
		for(int i=1,x,y;i<=m;++i)
		{
			cin>>x>>y;
			fa[find(y)]=find(x);
		}
		for(int i=1;i<=n;++i)
			if(i==fa[i])
				++ans;
		cout<<--ans<<endl;
	}
	return 0;
}
