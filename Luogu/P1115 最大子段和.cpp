#include<cstdio>
#include<iostream>
using namespace std;
long long dp[200005];
short a[200005];
int main()
{
	long long sum;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%hd",&a[i]);
	dp[0]=a[0];	sum=a[0];
	for(int i=1;i<n;i++)
	{
		if(dp[i-1]<0)
			dp[i]=a[i];
		else
			dp[i]=dp[i-1]+a[i];
		if(dp[i]>sum)
			sum=dp[i];
	}
	printf("%lld",sum);
	return 0;
}
