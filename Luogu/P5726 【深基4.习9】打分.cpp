#include<iostream>
#include<cstdio>
using namespace std;
int n,a[1100],sum,maxn,minn=0x7fffffff;
double ans;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	sum-=(maxn+minn);
	ans=(double)sum/(n-2);
	printf("%.2f",ans);
	return 0;
}
