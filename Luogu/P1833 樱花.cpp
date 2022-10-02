#include<iostream>
#include<cstdio>
using namespace std;
int tsh,tsm,teh,tem,T,n,N;
int Ti[100000],Ci[100000];
bool Pi[100000];
long long dp[1500];
int main()
{
	scanf("%d:%d %d:%d %d",&tsh,&tsm,&teh,&tem,&n);
	T=teh*60+tem-tsh*60-tsm;
	for(int i=1,t,c,p,j=1;i<=n;++i)
	{
		scanf("%d%d%d",&t,&c,&p);
		if(p==0)
		{
			Ti[j]=t; Ci[j]=c;	Pi[j]=false;
			++j;
		}
		else
		{
			int k=1;
			while(k<p)
			{
				p-=k;
				Pi[j]=true;	Ci[j]=c*k;	Ti[j]=t*k;
				++j;
				k*=2;
			}
			Pi[j]=true;	Ci[j]=c*p;	Ti[j]=t*p;
			++j;
		}
		N=j;
	}
	--N;
	for(int i=1;i<=N;++i)
	{
		if(!Pi[i])
		{
			for(int j=Ti[i];j<=T;++j)
				dp[j]=max(dp[j],dp[j-Ti[i]]+Ci[i]);
		}
		else
		{
			for(int j=T;j>=Ti[i];--j)
				dp[j]=max(dp[j],dp[j-Ti[i]]+Ci[i]);
		}
	}
	cout<<dp[T]<<endl;
	return 0;
}
