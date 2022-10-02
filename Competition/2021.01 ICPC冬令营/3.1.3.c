#include<stdio.h>
int main()
{
	int N=0;
	scanf("%d",&N); getchar();
	int win(char*,char);
	_Bool f[N];
	char s[3][3]={'\0'};
	int i=0,j=0,sumx=0,sumo=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%c%c%c",s[j],s[j]+1,s[j]+2);
			getchar();
		}
		sumx=0;	sumo=0;
		for(j=0;j<9;j++)
		{
			if(s[j/3][j%3]=='O')	sumo++;
			else if(s[j/3][j%3]=='X')	sumx++;
		}
		if(sumx<sumo||sumx>sumo+1)	f[i]=0;
		else if(sumx==sumo&&win(s[0],'X'))	f[i]=0;
		else if(sumx==sumo+1&&win(s[0],'O'))	f[i]=0;
		else if(win(s[0],'X')&&win(s[0],'O'))	f[i]=0;
		else	f[i]=1;
		if(i!=N-1)	getchar();
	}
	for(i=0;i<N;i++)
	{
		if(f[i])  printf("yes\n");
		else	printf("no\n");
	}
	return 0;
}
int win(char*p,char t)
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3&&*(p+i*3+j)==t;j++)
		if(j==3)	return 1;
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3&&*(p+i+j*3)==t;j++)
		if(j==3)	return 1;
	}
	return 0;
}
