#include<iostream>
using namespace std;
const int MAXN=500000+4;
int n,m;
int tree[MAXN],fd[MAXN];
inline int lowbit(int x)
{
	return x&-x;
}
inline void update(int i,int x)
{
	for(int pos=i;pos<=n;pos+=lowbit(pos))
		tree[pos]+=x;
}
inline int query(int x)
{
	int ans=0;
	for(int pos=x;pos;pos-=lowbit(pos))
		ans+=tree[pos];
	return ans;
}
int main()
{
	cin>>n>>m;
	for(int i=1,x,xx=0;i<=n;++i)
		cin>>x,update(i,x-xx),xx=x;
	for(int i=1,f,x,y,k;i<=m;++i)
	{
		cin>>f;
		switch(f)
		{
			case 1:
				cin>>x>>y>>k;
				update(x,k);
				update(y+1,-k);
				break;
			case 2:
				cin>>k;
				cout<<query(k)<<endl;
				break;
		}
	}
	return 0;
}
