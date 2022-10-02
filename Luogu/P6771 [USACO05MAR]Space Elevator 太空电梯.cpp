#include<iostream>
using namespace std;
short n,h[405],c[405],a[405];
bool dp[40005];
int main()
{
	short t;
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>h[i]>>a[i]>>c[i];
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=h[j];	h[j]=h[j+1];	h[j+1]=t;
				t=c[j];	c[j]=c[j+1];	c[j+1]=t;
				t=a[j];	a[j]=a[j+1];	a[j+1]=t;
			}
		}
	}
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=c[i];j++)
		{
			for(int k=a[i];k>=h[i];k--)
			{
				dp[k]|=dp[k-h[i]];
			}
		}
	}
	for(int i=a[n];i>=0;i--)
	{
		if(dp[i])
		{
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
