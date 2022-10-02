#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct WEALTH{
	int m,v;
	double p;
}s[150];
bool cmp(WEALTH a,WEALTH b)
{
	return (a.p>b.p);
}
int n,t;
double ans;
int main()
{
	cin>>n>>t;
	for(int i=1;i<=n;++i)
		cin>>s[i].m>>s[i].v,s[i].p=(double)s[i].v/(double)s[i].m;
	sort(s+1,s+n+1,cmp);
	for(int i=1,mmax=t;i<=n&&mmax>0;++i)
	{
		if(s[i].m>mmax)
		{
			ans+=(s[i].p*mmax);
			mmax=0;
		}
		else
		{
			ans+=s[i].v;
			mmax-=s[i].m;
		}
	}
	printf("%.2f",ans);
	return 0;
}
