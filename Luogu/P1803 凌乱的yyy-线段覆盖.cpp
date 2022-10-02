#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,ans;
struct ACTIVITY{
	int a,b;
}s[1000006];
bool cmp(ACTIVITY x,ACTIVITY y)
{
	return (x.b<y.b||x.b==y.b&&x.a<y.a);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		scanf("%d%d",&(s[i].a),&(s[i].b));
	sort(s+1,s+n+1,cmp);
	for(int i=1,end=-0x0fffffff;i<=n;++i)
	{
		if(s[i].a>=end)
			++ans,end=s[i].b;
	}
	cout<<ans;
	return 0;
}
