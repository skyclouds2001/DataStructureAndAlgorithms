#include<iostream>
using namespace std;
int N,M,f[10003],r[10003];
inline void init(int n)
{
	for(int i=1;i<=n;++i)
		f[i]=i,r[i]=1;
}
int find(int x)
{
	return (x==f[x])?x:(f[x]=find(f[x]));
}
void merge(int x,int y)
{
	int xx=find(x),yy=find(y);
	if(r[xx]<=r[yy])
		f[xx]=yy;
	else
		f[yy]=xx;
	if(xx==yy&&xx!=yy)
		r[yy]++;
}
int main()
{
	cin>>N>>M;
	init(N);
	for(int i=1,s,x,y;i<=M;++i)
	{
		cin>>s>>x>>y;
		if(s==1)
			merge(x,y);
		if(s==2)
			cout<<((find(x)==find(y))?'Y':'N')<<endl;
	}
	return 0;
}
