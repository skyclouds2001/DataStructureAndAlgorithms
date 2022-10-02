#include<cstdio>
using namespace std;
int a[1000];
int main()
{
	int n,m,t;
	scanf("%d%d",&n,&m);
	for(int k=1;k<=m;k++)
	{
		scanf("%d",&t);
		a[t]++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			printf("%d ",i);
		}
	}
	return 0;
 } 
