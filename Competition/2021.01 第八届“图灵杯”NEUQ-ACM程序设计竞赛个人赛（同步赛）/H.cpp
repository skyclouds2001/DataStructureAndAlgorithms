#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int f(int n)
{
	return ((int)pow(150994941,n/31)%998244353)*(((int)pow(2,n%31))%998244353)%998244353;
}
int main()
{
	int T,n,m;
	unsigned long long ans;
	cin>>T;
	for(int k=0;k<T;k++)
	{
		cin>>n>>m;
		if(m==0)
		{
			ans=n+2;
			ans%=998244353;
		}
		else if(m==1)
		{
			ans=n*2;
			ans%=998244353;
		}
		else if(m==2)
		{
			ans=f(n);
			ans%=998244353;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
