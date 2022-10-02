#include<iostream>
using namespace std;
int n,m,tree[100004];	//表示经过几次操作 
inline int lowbit(int x)
{
	return x&-x;
}
void update(int i,int x)
{
	for(int pos=i;pos<=n;pos+=lowbit(pos))
		tree[pos]+=x;
}
int query(int i)
{
	int ans=0;
	for(int pos=i;pos;pos-=lowbit(pos))
		ans+=tree[pos];
	return ans;
}
bool ff(int x)
{
	return (x%2==0)?false:true;
}
int main()
{
	cin>>n>>m;
	for(int i=1,f,x,y,k;i<=m;++i)
	{
		cin>>f;
		switch(f)
		{
			case 1:
				cin>>x>>y;
				update(x,1);
				update(y+1,-1);
				break;
			case 2:
				cin>>k;
				cout<<ff(query(k))<<endl;
				break;
		}
	}
	return 0;
}
