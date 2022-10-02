#include<bits/stdc++.h>
using namespace std;
int father[10000],n,m,p;
int find(int x)
{
	return (x==father[x])?x:(find(father[x]));
}
int main()
{
	cin>>n>>m>>p;
	for(int i=1;i<=n;++i)
		father[i]=i;
	for(int i=1,x,y;i<=m;++i)
		cin>>x>>y,father[find(y)]=find(x);
	for(int i=1,x,y;i<=p;++i)
		cin>>x>>y,cout<<((find(father[x])==find(father[y]))?"Yes":"No")<<endl;
	return 0;
}
