#include<stdio.h>
int main()
{
	int n=0,m=0;
	char d=0;
	scanf("%d %d %c",&n,&m,&d);  getchar();
	char s[n][m];
	int i=0,j=0,k=0;
	int ox[n*m],oy[n*m];
	_Bool flag=1;
	int N=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			s[i][j]=getchar();
			if(s[i][j]=='o')
			{
				ox[N]=i;  oy[N]=j;
				N++;
			}
		}
		if(i!=n-1)  getchar();
	}
	for(k=0;k<N&&flag;k++)
	{
		switch(d)
		{
			case 'v':for(i=ox[k],j=oy[k];i<n&&s[i][j]!='x';i++); if(i!=n)  flag=0;break;
			case '^':for(i=ox[k],j=oy[k];i>=0&&s[i][j]!='x';i--); if(i!=-1)  flag=0;break;
			case '<':for(i=ox[k],j=oy[k];j>=0&&s[i][j]!='x';j--); if(j!=-1)  flag=0;break;
			case '>':for(i=ox[k],j=oy[k];j<m&&s[i][j]!='x';j++); if(j!=m)  flag=0;break;
		}
	}		
	if(flag)  printf("OK");
	else  printf("GG");
	return 0;
}
