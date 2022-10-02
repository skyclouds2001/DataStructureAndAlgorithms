#include<stdio.h>
int main()
{
	int T=0,n=0;
	unsigned int a[100][100]={0};
	int i=0,j=0,k=0;
	scanf("%d",&T);
	for(k=0;k<T;k++)
	{
		getchar();
		scanf("N = %d",&n);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%u",&a[i][j]);
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[i][j]<0||a[i][j]!=a[n-1-i][n-1-j])
					goto LABER;
			}
		}
		LABER:
		if(i==n&&j==n)	printf("Test #%d: Symmetric.\n",k+1);
		else	printf("Test #%d: Non-symmetric.\n",k+1);
	}
	return 0;
}
/*
2
N = 3
5 1 3
2 0 2
3 1 5
N = 3
5 1 3
2 0 2
0 1 5

Test #1: Symmetric.
Test #2: Non-symmetric.
*/
