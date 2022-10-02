#include<stdio.h>
int main()
{
	int n=0,i=0,j=0,t=0;
	scanf("%d",&n);
	int a[n];
	_Bool f[n-1];
	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
		if(i!=n-1)	f[i]=0;
	}
	for(i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])	t=a[i]-a[i+1];
		else	t=a[i+1]-a[i];
		if(t>0&&t<n)	f[t-1]=1;
	}
	for(i=0;i<n-1;i++)
	{
		if(!f[i])	break;
	}
	if(i==n-1)	printf("Jolly");
	else	printf("Not jolly");
	return 0;
}
