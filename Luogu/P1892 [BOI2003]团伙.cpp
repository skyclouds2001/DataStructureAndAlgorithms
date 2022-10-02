#include<iostream>
using namespace std;
int n,m,ans;
int fa[2008];
inline int find(int x)
{
	return (fa[x]==x)?x:(fa[x]=find(fa[x]));
}
inline void merge(int x,int y)
{
	fa[find(x)]=find(y);
}
int main()
{
	cin>>n>>m;
	char opt;	int p,q;
	for(int i=1;i<=n*2;++i)
		fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		cin>>opt>>p>>q;
		switch(opt)
		{
			case 'F':
				merge(p,q);
				break;
			case 'E':
				merge(p+n,q);
				merge(q+n,p);
				break;
		}
	}
	for(int i=1;i<=n;++i)
		if(fa[i]==i)
			++ans;
	cout<<ans<<endl;
	return 0;
}
