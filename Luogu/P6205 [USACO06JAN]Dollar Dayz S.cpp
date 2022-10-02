#include<iostream>
#include<cstdio>
using namespace std;
short K,N;
__int128 dp[1001];
void op(__int128 x)
{
	if(x==0)
	{
		putchar('0');
		return;
	}
	if(x>=10) op(x/10);
	putchar(x%10+'0');
}
int main()
{
	cin>>N>>K;
	dp[0]=1;
	for(int i=1;i<=K;i++)
	{
		for(int j=i;j<=N;j++)
		{	
			dp[j]+=dp[j-i];
		}
	}
	op(dp[N]);
	putchar('\n');
	return 0;
 } 
