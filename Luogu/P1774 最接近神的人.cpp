#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[500000+4],n;
struct c{
	int num,id;
	bool operator<(c z)
	{
		return (this->num<z.num or (this->num==z.num and this->id<z.id));
	}
}b[500000+4];
long long ans,tree[500000+4];
inline long long query(int x)
{
	long long sum=0;
	for(int i=x;i;i-=i&-i)
		sum+=tree[i];
	return sum;
}
inline long long update(int p,int x=1)
{
	for(int i=p;i<=n;i+=i&-i)
		++tree[i];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&(b[i].num)),b[i].id=i;
	sort(b+1,b+n+1);
	for(int i=1;i<=n;++i)
		a[b[i].id]=i;
	for(int i=1;i<=n;++i)
		ans+=query(a[i]),update(a[i],1);
	printf("%lld\n",(long long)n*(n-1)/2-ans);
	return 0;
}
