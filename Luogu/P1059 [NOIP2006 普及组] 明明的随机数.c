#include<stdio.h>
#include<stdlib.h>
int main()
{
	int N=0,M=0;
	int i,j;
	short check(short *,int);
	scanf("%d",&N);
	short a[N],b[N],t;
	for(i=0;i<N;i++)
	{
		scanf("%hd",a+i);
	    b[i]=0;
	}
	for(i=0,M=0;i<N;i++)
	{
		if(check(a,i))
		{
			b[M]=a[i];
			M++;
		}
	}
	for(i=0;i<M;i++)
	{
		for(j=0;j<M-1-i;j++)
		{
			if(b[j]>b[j+1])
			{
				t=b[j];  b[j]=b[j+1];  b[j+1]=t;
			}
		}
	}
	printf("%d\n",M);
	for(i=0;i<M;i++)
	{
		printf("%hd ",b[i]);
	}
}
short check(short *p,int s)
{
	int i;
	for(i=0;i<s;i++)
	{
		if(*(p+i)==*(p+s))  return 0;
	}
	return 1;
}
