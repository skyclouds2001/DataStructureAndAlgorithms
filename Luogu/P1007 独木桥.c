#include<stdio.h>
int max(int a,int b)
{
	return (a>b)?a:b;
}
int min(int a,int b)
{
	return (a<b)?a:b;
}
int main()
{
	int L=0,N=0;
	int mint=0,maxt=0;
	scanf("%d%d",&L,&N);
	int x[3][N];
	int i=0,j=0;
	for(i=0;i<N;i++)
	{
		scanf("%d",x[0]+i);
		x[1][i]=L+1-x[0][i];
	}
	for(i=0;i<N;i++)
	{
		if(max(x[0][i],x[1][i])==x[1][i])
		{
			if(mint<x[0][i]) mint=x[0][i];
			if(maxt<x[1][i]) maxt=x[1][i];
		}
		else if(max(x[0][i],x[1][i])==x[0][i])
		{
			if(mint<x[1][i]) mint=x[1][i];
			if(maxt<x[0][i]) maxt=x[0][i];
		}
	}		
	printf("%d %d",mint,maxt);
	return 0;
 } 
