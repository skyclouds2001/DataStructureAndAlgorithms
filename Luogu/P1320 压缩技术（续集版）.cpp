#include<stdio.h>
#include<string.h>
char hz[301][301];
short c[60000];
int main()
{
	int n=200,count=0,k=0;
	char t=0;
	for(int i=0;i<n;i++)
	{
		scanf("%s",hz[i]);
		if(i==0)	n=strlen(hz[0]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0&&j==0)
			{
				t=hz[i][j];
				if(t=='1')
				{
					c[k]=0;
					k++;
				}
			}
			else
			{
				if(t!=hz[i][j])
				{
					c[k]=count;
					count=0;
					k++;
					t=hz[i][j];
				}
			}
			count++;
		}
	}
	c[k]=count;
	printf("%d ",n);
	for(int i=0;i<k;i++)
		printf("%d ",c[i]);
	printf("%d\n",c[k]);
	return 0;
}
