#include<iostream>
#include<cstdio>
using namespace std;
long long n,f,mainf;
long long tree[200000+4],sum[200000+4];
inline long long lowbit(long long x)
{
	return x&-x ;
}
inline void update(int i,long long x)
{
	for(int p=i;p<=n;p+=lowbit(p))
		tree[p]+=x,sum[p]+=x*i;		//
}
inline long long query(int i)
{
	long long ans=0;
	for(int p=i;p;p-=lowbit(p))
		ans+=tree[p]*(i+1)-sum[p];		//
	return ans;
}
int main()
{
	cin>>n>>f;
	long long opr=0,l=0,r=0,k=0,t=0,pre=0;
	for(int i=1,t;i<=n;++i)
		scanf("%lld",&t),update(i,t-pre),pre=t;
	for(int i=1;i<=f;++i)
	{
		cin>>opr;
		switch(opr)
		{
			case 1:
				scanf("%lld%lld%lld",&l,&r,&k);
				update(l,k);
				update(r+1,-k);
				break;
			case 2:
				scanf("%lld",&k);
				mainf+=k;
				break;
			case 3:
				scanf("%lld",&k);
				mainf-=k;
				break;
			case 4:
				cin>>l>>r;
				printf("%lld\n",query(r)-query(l-1)+mainf*(l==1));
				break;
			case 5:
				printf("%lld\n",tree[1]+mainf);
				break;
		}
	}
	return 0;
}
