#include<bits/stdc++.h>
using namespace std;
int h[100005],f[100005],g[100005];
int n,p,q;
int main()
{
	for(int k=1;scanf("%d",&h[k])!=EOF;++k) ++n;
	f[1]=h[1];	
	p=1;
	for(int i=2;i<=n;++i)
		if(f[p]>=h[i])
			f[++p]=h[i];
		else
		{
			int l=1,r=p,mid;
			while(l<r)
			{
				mid=(l+r)>>1;
				if(f[mid]>=h[i])
					l=mid+1;
				else
					r=mid;
			}
			f[l]=h[i];
		}
	cout<<p<<endl;
	g[1]=h[1];	
	p=1;
	for(int i=2;i<=n;++i)
		if(g[p]<h[i])
			g[++p]=h[i];
		else
		{
			int l=1,r=p,mid;
			while(l<r)
			{
				mid=(l+r)>>1;
				if(g[mid]<h[i])
					l=mid+1;
				else
					r=mid;
			}
			g[l]=h[i];
		}
	cout<<p<<endl;
	return 0;
}
//389 207 155 300 299 170 158 65
