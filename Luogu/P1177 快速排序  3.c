#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void sort_fast(int*,int,int);
int main()
{
	int N=0;
	scanf("%d",&N);
	int a[N];
	int i=0;
	srand(time(NULL));
	for(i=0;i<N;i++)  scanf("%d",a+i);
	sort_fast(a,0,N-1);
	for(i=0;i<N;i++)  printf("%d ",a[i]);
	return 0;
}
void sort_fast(int*a,int l,int r)
{
	if(l>=r)  return;		
	if(l-r>10)
	{
		int i=l,j=r;
		int k=rand()%(r-l+1)+l;  /*优化：随机化比较值*/
		int x=*(a+k);
		*(a+k)=*(a+i);
		while(i<j)
		{		
			for(;*(a+j)>x&&i<j;j--)  ;
			if(i<j)  *(a+i)=*(a+j);
			for(;*(a+i)<=x&&i<j;i++)  ;
			if(i<j)  *(a+j)=*(a+i);
		}
		*(a+i)=x;	
		sort_fast(a,l,i-1);
		sort_fast(a,i+1,r);
	}
	else  /*优化：小区间插入排序*/
	{
		int i=0,j=0;
		int t=0;
		_Bool flag=0; 
		for(i=l;i<=r;i++)
		{
			for(j=l,flag=0;j<=r-1;j++)
			{
				if(*(a+j)>*(a+j+1))
				{
					t=*(a+j);  *(a+j)=*(a+j+1);  *(a+j+1)=t;  flag=1;
				}
			}
			if(!flag)  break;
		}
	}
}
