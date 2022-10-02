#include<cstdio>
using namespace std;
int a[1000005];
int main()
{
	int n,m,q;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int k=0,i,j,mid;k<m;k++)
	{
		scanf("%d",&q);
		i=0;	j=n-1;
		while(i<=j)
		{
			mid=i+(j-i)/2;
			if(a[mid]>=q)
				j=mid-1;
			else if(a[mid]<q)
				i=mid+1;
		}
		if(a[i]==q)
		{
			printf("%d",i+1);
		}
		else
			printf("-1");
		if(k<m-1)	putchar(' ');
		else if(k==m-1)	putchar('\n');
	}
	return 0;
} 
