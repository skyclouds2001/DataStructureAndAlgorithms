#include<stdio.h>
typedef struct{
	int number;
	int count;
}NUM;
NUM num[1000],temp;
int main()
{
	int N=0,C=0,n=0;
	int i=0,j=0,t=0;
	scanf("%d%d",&N,&C);
	for(i=0;i<N;i++)
	{
		scanf("%d",&t);
		for(j=0;j<n;j++)
		{
			if(num[j].number==t)
			{
				num[j].count++;
				break;
			}
		}
		if(j==n)
		{
			num[j].number=t;
			num[j].count++;
			n++;
		}
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(num[j].count<num[j+1].count)
			{
				temp=num[j];	num[j]=num[j+1];	num[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<num[i].count;j++)
		{
			printf("%d ",num[i].number);
		}
	}
	return 0;
}
