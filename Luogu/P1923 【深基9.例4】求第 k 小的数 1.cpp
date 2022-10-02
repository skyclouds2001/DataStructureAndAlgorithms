#include<iostream>
#include<cstdio>
using namespace std;
int a[5000000],n,k,ans;
void sortsearch(int,int);
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sortsearch(0,n-1);
	printf("%d",ans);
	return 0;
}
void sortsearch(int l,int r)
{
	if(l>=r)
	{
		if(l==k)	ans=a[k];
		else if(r==k)	ans=a[k];
		return;
	}
	else
	{
		int i=l,j=r;
		int x=a[i];
		while(i<j)
		{		
			for(;a[j]>x&&i<j;j--);
			if(i<j)  a[i]=a[j];
			for(;a[i]<=x&&i<j;i++);
			if(i<j)  a[j]=a[i];
		}
		a[i]=x;
		if(k<=j)
			sortsearch(l,i-1);
		else if(k>=i)
			sortsearch(i+1,r);
		else
			ans=a[j+1];
	}
}
