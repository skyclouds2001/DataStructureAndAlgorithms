#include<iostream>
using namespace std;
int n,fa[204],ans;
bool flag[204];
int find(int x)
{
	return (x==fa[x])?x:(fa[x]=find(fa[x]));
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		fa[i]=i;
	for(int i=1,x,y;i<=n;++i)
	{
		y=find(i);
		while(true)
		{
			cin>>x;
			if(x==0)
				break;
			flag[x]=true;
			fa[find(x)]=y;
		}
	}
	for(int i=1;i<=n;++i)
		if(fa[i]==i or not flag[i])
			++ans;
	cout<<ans<<endl;
	return 0;
}
/*我们不管那些特殊点（比如33），用一个数组存一下每一个点有没有直系
的父亲,其他的跟并查集没啥区别。

最后O(n)O(n) 扫一遍的时候加以判断，如果是没有直系父亲的，直接加
一，其他的如果是祖先也加一。*/
