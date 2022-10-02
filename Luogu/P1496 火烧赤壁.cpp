#include<iostream>
#include<cstdio>
using namespace std;
int n,a[20004],b[20004],length,end;
void sort_fast(int l,int r)
{
	if(l>=r)  return;		
	else
	{
		int i=l,j=r,x=a[i],y=b[i];
		while(i<j)
		{		
			for(;a[j]>x&&i<j;j--)	;
			if(i<j)	{	a[i]=a[j];	b[i]=b[j];	}
			for(;a[i]<=x&&i<j;i++)	;
			if(i<j)	{	a[j]=a[i];	b[j]=b[i];	}
		}
		a[i]=x;		b[i]=y;
		sort_fast(l,i-1);
		sort_fast(i+1,r);
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d%d",&a[i],&b[i]);
	sort_fast(0,n-1);
	end=b[0];
	length=b[0]-a[0];
	for(int i=1;i<n;i++)
	{
		if(end<=a[i])
		{
			length+=(b[i]-a[i]);
			end=b[i];
		}
		else if(end<b[i])	//end>a[i]
		{
			length+=(b[i]-end);
			end=b[i];
		}
		else if(end>=b[i])	//end>a[i]
		{
			continue;
		}
	}
	cout<<length<<endl;
	return 0;
}
