#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
long long ans;
struct TEST{
	int p,c;
}s[100005];
bool cmp(TEST a,TEST b)
{
	return (a.p<b.p);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>s[i].p>>s[i].c;
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=n;++i)
		if(s[i].c>s[i-1].c)
			ans+=s[i].c-s[i-1].c;
	cout<<ans;
	return 0;
}
