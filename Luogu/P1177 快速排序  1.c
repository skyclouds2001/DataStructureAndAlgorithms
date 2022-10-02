#include<stdio.h>
void sort_fast(int*,int,int);
int sort_fast_position(int*,int,int);
int main()
{
	int a[15]={1,4,14,6,9,8,12,3,13,15,2,7,5,11,10},i=0;
	sort_fast(a,0,14);
	for(i=0;i<15;i++)  printf("%d ",a[i]);
	return 0;
}
void sort_fast(int*a,int l,int r)
{
	if(l>=r)  return;
	int p=sort_fast_position(a,l,r);	
	sort_fast(a,l,p-1);
	sort_fast(a,p+1,r);
}
int sort_fast_position(int* a,int l,int r)
{
	int i=l,j=r,x=*(a+l);
	while(i<j)
	{		
		for(;*(a+j)>x&&i<j;j--)  ;
		if(i<j)  *(a+i)=*(a+j);
		for(;*(a+i)<=x&&i<j;i++)  ;
		if(i<j)  *(a+j)=*(a+i);
	}
	*(a+i)=x;
	return i;
}
