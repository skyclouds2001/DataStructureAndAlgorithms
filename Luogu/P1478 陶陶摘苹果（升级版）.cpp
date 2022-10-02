#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,s,a,b,N,ans;
struct APPLE{
	int x,y;
}t[10000];
bool cmp(APPLE a,APPLE b)
{
	return (a.y<b.y);		//²»ÄÜ¼Ó= 
}
int main()
{
	cin>>n>>s>>a>>b;
	for(int i=1,j=1,x,y;i<=n;++i)
	{
		scanf("%d%d",&x,&y);
		if(x<=a+b)
			t[j].x=x,t[j].y=y,N=j,++j;
	}
	sort(t+1,t+N+1,cmp);
	for(int i=1,k=s;i<=N;++i)
	{
		if(k>=t[i].y)
			k-=t[i].y,++ans;
		else
			break;
	}
	cout<<ans;
	return 0;
}
