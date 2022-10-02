#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n],f[n],r[n];
	int i=0,k=0,t=0,j=0;
	for(i=0;i<n;i++)	scanf("%d",a+i);
	for(i=0,k=1;i<n-1;i++)
	{
		if(a[i]<a[i+1]) p[i]=k;
		else
		{
			p[i]=k; k++;			
		}
	}
	p[n-1]=k;
	
	return 0;
}
/*#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i=0,j=0,k=0,p=0;
	for(i=0;i<n;i++) scanf("%d",a+i);
	for(j=0;j<n;j++)
	{
		k=1;
		p=j;
		for(i=j-1;i>=0;i--)
		{
			if(a[j]>a[i]) p--;
			else if(a[j]<a[i]&&k) {p--;k=0;}
			else break;
		}
		printf("%d\n",p+1);
	}
	return 0;
}*/
