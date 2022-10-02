#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[500000+4];
long long ans,tree[500000+4];
struct FLOW{
	int num,flow;
	bool operator<(FLOW b)
	{
		return this->num<b.num or (this->num==b.num and this->flow<b.flow);
	}
}b[500000+4];
inline long long query(int x)
{
	long long ans=0;
	for(int i=x;i;i-=(i&-i))
		ans+=tree[i];
	return ans;
}
inline void update(int p,int x=1)
{
	for(int i=p;i<=n;i+=(i&-i))
		tree[i]+=x;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&(b[i].num)),b[i].flow=i;
	sort(b+1,b+n+1);
	for(int i=1;i<=n;++i)
		a[b[i].flow]=i;
	for(int i=1;i<=n;++i)
	{
		ans+=query(a[i]);
		update(a[i],1);
	}
	printf("%lld\n",(long long)n*(n-1)/2-ans);
	return 0;
}
