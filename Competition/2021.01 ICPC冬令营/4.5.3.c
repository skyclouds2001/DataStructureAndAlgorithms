#include<stdio.h>
#include<memory.h>
int main()
{
	int N=0,smax=0,dmax=0;
	scanf("%d",&N);
	short a[N][N],num[N],d[N];
	int i=0,j=0,k=0,l=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%hd",&a[i][j]);
		}
	}
	for(i=0;i<N;i++)
	{
		memset(num,0,N*sizeof(int));
		for(j=i;j<N;j++)
		{
			for(k=0;k<N;k++)
				num[k]+=a[j][k];
			d[0]=num[0];	dmax=d[0];
			for(k=1;k<N;k++)
			{
				d[k]=(d[k-1]>0)?(d[k-1]+num[k]):num[k];
				dmax=(d[k]>dmax)?d[k]:dmax;
			}
			smax=(smax>dmax)?smax:dmax;
		}
	}
	printf("%d",smax);
	return 0;
}
