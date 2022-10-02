#include<iostream>
#include<algorithm>
using namespace std;
int N,M,a,b,c,ans;
int fa[20000*2+4];
class CRIME{
	public:
		int a,b,c;
}s[100000+4];
bool cmp(CRIME x,CRIME y)
{
	return x.c>y.c;
}
int find(int x)
{
	return (x==fa[x])?x:(fa[x]=find(fa[x]));
}
int main()
{
	cin>>N>>M;
	for(int i=1;i<=N*2;++i)
		fa[i]=i;
	for(int i=1;i<=M;++i)
		cin>>s[i].a>>s[i].b>>s[i].c;
	sort(s+1,s+M+1,cmp);
	for(int i=1;i<=M;++i)
	{
		a=s[i].a;	b=s[i].b;	c=s[i].c;
		if(find(a)==find(b))
		{
			ans=s[i].c;
			break;
		}
		else
		{
			fa[find(b+N)]=find(a);
			fa[find(a+N)]=find(b);
		}
	}
	cout<<ans<<endl;
	return 0;
}
