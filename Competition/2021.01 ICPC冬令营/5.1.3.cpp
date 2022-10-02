#include<stdio.h>
int main()
{
	int n=0,m=0;
	scanf("%d %d",&n,&m);	getchar();
	char s[m+1][n+2];
	unsigned f[m];
	for(int i=0;i<m;i++)
	{
		gets(s[i]);
		f[i]=0;
		for(int j=0;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(s[i][j]>s[i][k])		f[i]++;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		unsigned min=f[0],minp=0;
		for(int j=1;j<m;j++)
		{
			if(f[j]<min)
				minp=j;
		}
		puts(s[minp]);
		f[minp]=0xFFFFFFFF;
	}
	return 0;
}
