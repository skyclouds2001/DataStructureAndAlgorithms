#include<iostream>
using namespace std;
int n,w;
long long tree[100000+4];
void update(int i,int x)
{
	for(int pos=i;pos<=n;pos+=(pos&-pos))
		tree[pos]+=x;
}
long long query(int x)
{
	long long ans=0;
	for(int pos=x;pos;pos-=(pos&-pos))
		ans+=tree[pos];
	return ans;
}
int main()
{
	cin>>n>>w;
	char t;	int a,b;
	for(int i=1;i<=w;++i)
	{
		cin>>t>>a>>b;
		switch(t)
		{
			case 'x':
				update(a,b);
				break;
			case 'y':
				cout<<query(b)-query(a-1)<<endl;
				break;
		}
	}
	return 0;
}
