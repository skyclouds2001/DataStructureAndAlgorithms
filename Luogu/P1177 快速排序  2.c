#include<stdio.h>
void sort_fast(int*,int,int);
int main()
{
	int a[20]={1,19,4,14,6,9,16,8,20,12,3,13,17,15,2,7,18,5,11,10},i=0;
	sort_fast(a,0,19);
	for(i=0;i<20;i++)  printf("%d ",a[i]);
	return 0;
}
void sort_fast(int*a,int l,int r)
{
	if(l>=r)  return;
	int i=l,j=r;
	int x=*(a+i);
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
