#include<cstdio>
#include<cstring>
using namespace std;
short fac[100],sum[100],n;
int main()
{
	fac[0]=1;
	sum[0]=1;
	scanf("%hd",&n);
	for(int i=2,j,k;i<=n;i++)
	{
		j=0;
		while(j<100)
		{
			fac[j]*=i;
			j++;
		}
		j=0;
		while(j<100)
		{
			fac[j+1]+=fac[j]/10;
			fac[j]%=10;
			j++;
		}
		j=0;
		while(j<100)
		{
			sum[j]+=fac[j];
			sum[j+1]+=sum[j]/10;
			sum[j]%=10;
			j++;
		}
	}
	for(int k=99;sum[k]==0;k--)	n=k-1;
	for(int i=n;i>=0;i--)
		printf("%hd",sum[i]);
	return 0;
}
