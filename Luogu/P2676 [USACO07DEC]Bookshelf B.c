#include<stdio.h>
void sort_fast(int *a,int l,int r)
{
	if(l>=r)  return;		
	else
	{
		int i=l,j=r;
		int x=*(a+i);
		while(i<j)
		{		
			for(;*(a+j)>x&&i<j;j--);
			if(i<j)  *(a+i)=*(a+j);
			for(;*(a+i)<=x&&i<j;i++);
			if(i<j)  *(a+j)=*(a+i);
		}
		*(a+i)=x;	
		sort_fast(a,l,i-1);
		sort_fast(a,i+1,r);
	}
}
int main()
{
	int N=0,B=0,count=0,S=0;
	int i=0;
	scanf("%d%d",&N,&B);
	int H[N];
	for(;i<N;i++)	scanf("%d",&H[i]);
	sort_fast(H,0,N-1);
	i=N-1;
	while(S<B&&i>=0)
	{
		S+=H[i];
		i--;
		count++;
	}
	printf("%d",count);
	return 0;
}
