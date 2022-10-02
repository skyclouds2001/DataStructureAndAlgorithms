#include<iostream>
using namespace std;
int n,m;
struct ITEM{
	int v,w,q; 
	struct ITEM *p[2];
}item[100];
int dp[40000]; 
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>item[i].v>>item[i].w>>item[i].q;
		if(item[i].q!=0)
			if(item[item[i].q].p[0]==NULL)
				item[item[i].q].p[0]=&(item[i]);
			else
				item[item[i].q].p[1]=&(item[i]);
	}
	for(int i=1;i<=m;++i)
	{
		struct ITEM *p0=NULL,*p1=NULL,*p2=NULL;
		if(item[i].q!=0)	continue;
		for(int j=n;j>=item[i].v;--j)
		{
			p0=&item[i];
			p1=item[i].p[0];	p2=item[i].p[1];
			dp[j]=max(dp[j],dp[j-p0->v]+(p0->v)*(p0->w));
			if(p1&&j>=p0->v+p1->v)
				dp[j]=max(dp[j],dp[j-p0->v-p1->v]+(p0->v)*(p0->w)+(p1->v)*(p1->w));
			if(p2&&j>=p0->v+p2->v)
				dp[j]=max(dp[j],dp[j-p0->v-p2->v]+(p0->v)*(p0->w)+(p2->v)*(p2->w));
			if(p1&&p2&&j>=p0->v+p1->v+p2->v)
				dp[j]=max(dp[j],dp[j-p0->v-p1->v-p2->v]+(p0->v)*(p0->w)+(p1->v)*(p1->w)+(p2->v)*(p2->w));
		}
	}
	cout<<dp[n];
	return 0;
}
