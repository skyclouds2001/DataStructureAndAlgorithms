#include<iostream>
using namespace std;
int n,m,tree[10000000+4];
inline int lowbit(int x)
{
	return x&-x;
}
inline void update(int i,int x)
{
	for(int pos=i;pos<=n;pos+=lowbit(pos))
		tree[pos]+=x;
}
inline int query(int i)
{
	int ans=0;
	for(int pos=i;pos;pos-=lowbit(pos))
		ans+=tree[pos];
	return ans;
}
int main()
{
	cin>>n>>m;
	for(int i=1,f,a,b;i<=m;++i)
	{
		cin>>f;
		switch(f)
		{
			case 0:
				cin>>a>>b;
				update(a,1);
				update(b+1,-1);
				break;
			case 1:
				cin>>a;
				cout<<query(a)<<endl;
				break;
		}
	}
	return 0;
}
