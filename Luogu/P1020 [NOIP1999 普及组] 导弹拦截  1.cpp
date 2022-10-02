#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int h[100005],f[100005],g[100005];
int n,ansf,ansg;
int main()
{
	for(int k=1;scanf("%d",&h[k])!=EOF;++k) ++n,f[k]=1,g[k]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<i;++j)
		{
			if(h[j]>=h[i])
				f[i]=max(f[i],f[j]+1);
		}
		ansf=max(ansf,f[i]);
	}
	printf("%d\n",ansf);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<i;++j)
		{
			if(h[j]<h[i])
				g[i]=max(g[i],g[j]+1);
		}
		ansg=max(ansg,g[i]);
	}
	printf("%d\n",ansg);
	return 0;
}
//389 207 155 300 299 170 158 65
