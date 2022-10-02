#include<iostream>
using namespace std;
const int MAXN=500000+4;
int n,m,tree[MAXN];
inline int lowbit(int x)
{
	return (x&(-x));
}
inline void update(int i,int x)
{
	for(int p=i;p<=n;p+=lowbit(p))
		tree[p]+=x;
}
inline int query(int n)
{
	int ans=0;
	for(int p=n;p;p-=lowbit(p))
		ans+=tree[p];
	return ans;
}
inline int query(int a,int b)
{
	return query(b)-query(a-1);
}
int main()
{
	cin>>n>>m;
	for(int i=1,x;i<=n;++i)
		cin>>x,update(i,x);
	for(int i=1,f,x,k,y;i<=m;++i)
	{
		cin>>f;
		switch(f)
		{
			case 1:
				cin>>x>>k;
				update(x,k);
				break;
			case 2:
				cin>>x>>y;
				cout<<query(x,y)<<endl;
				break;
		}
	}
	return 0;
}
