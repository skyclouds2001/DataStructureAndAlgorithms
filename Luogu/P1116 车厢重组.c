#include<stdio.h>
int main()
{
	int N=0,count=0;
	int i=0,j=0,t=0;
	scanf("%d",&N);
	int a[N];
	for(i=0;i<N;i++)	scanf("%d",a+i);
	for(i=0;i<N-1;i++)
	{
		for(j=0;j<N-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];		a[j]=a[j+1];	a[j+1]=t;
				count++;
			}
		}
	}
	printf("%d",count);
	return 0;
}
