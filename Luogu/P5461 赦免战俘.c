#include<stdio.h>
#include<math.h>
void kk(short*,short,short,short,short);
int main()
{
	short n=0;
	scanf("%hd",&n);
	const short N=(short)pow(2,(double)n);
	short a[N][N];
	short i=0,j=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			a[i][j]=1;
		}
	}	
	kk(a[0],N,N,0,0);
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(j==N-1)  printf("%hd",a[i][j]);
			else  printf("%hd ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
void kk(short*a,short N,short b,short x,short y)
{
	short i=0,j=0;
	if(b==1)  ;
	else if(b==2)  *(a+x*N+y)=0;
	else if(b>2)
	{
		for(i=x;i<x+b/2;i++)
		{
			for(j=y;j<y+b/2;j++)
			{
				*(a+N*i+j)=0;
			}			
		}
		kk(a,N,b/2,x,y+b/2);
		kk(a,N,b/2,x+b/2,y+b/2);
		kk(a,N,b/2,x+b/2,y);
	}
}
