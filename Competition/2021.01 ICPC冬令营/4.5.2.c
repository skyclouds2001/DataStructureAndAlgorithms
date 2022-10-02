#include<stdio.h>
int a[1000][1000]={0};
int main()
{
	int n=0;
	int i=0,j=0;
	while(1)
	{
		scanf("%d",&n);
		if(!n)	goto END;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-1;j++)
			{
				if(a[i][j]+a[i+1][j+1]!=a[i+1][j]+a[i][j+1])
				{
					goto QUIT;
				}
			}
		}
		QUIT:
		if(i==n-1&&j==n-1)	printf("homogeneous\n");
		else	printf("not homogeneous\n");
	}
	END:
	return 0;
}
/*
Sample Input
2
1 2
3 4
3
1 3 4
8 6 -2
-3 4 0
0
Sample Output
homogeneous
not homogeneous
*/
