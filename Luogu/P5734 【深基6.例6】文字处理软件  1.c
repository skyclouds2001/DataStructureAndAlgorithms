#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
	char file[2000]={'\0'},cmd[500]={'\0'};
	int q=0,i=0;
	void f1(char*,char*); void f2(char*,char*);
	void f3(char*,char*); void f4(char*,char*);
	scanf("%d",&q);	getchar();
	gets(file);
	for(i=0;i<q;i++)
	{
		gets(cmd);
		switch(cmd[0])
		{
			case '1':f1(cmd,file);break;
			case '2':f2(cmd,file);break;
			case '3':f3(cmd,file);break;
			case '4':f4(cmd,file);break;
		}
	}
	return 0;
}

void f1(char *c,char *f)
{
	strcat(f,c+2);
	printf("%s\n",f);
}

void f2(char *c,char *f)
{
	char ls[500]={'\0'};
	int a=0,b=0;
	int i=2;
	while(isdigit(c[i]))
	{
		a*=10;	a+=(c[i]-'0');
		i++;
	}
	i++;
	while(isdigit(c[i]))
	{
		b*=10;	b+=(c[i]-'0');
		i++;
	}
	strncpy(ls,f+a,b);
	strcpy(f,ls);
	printf("%s\n",f);
}

void f3(char *c,char *f)
{
	char ls[500]={'\0'};
	int i=2,a=0;
	while(isdigit(c[i]))
	{
		a*=10;	a+=(c[i]-'0');
		i++;
	}
	i++;
	strcpy(ls,f+a);
	strcpy(f+a,c+i);
	strcat(f,ls);
	printf("%s\n",f);
}

void f4(char *c,char *f)
{
	int N=strlen(f),n=strlen(c+2),i=0;
	_Bool flag=0;
	for(i=0;i<N-n+1;i++)
	{
		if(!strncmp(f+i,c+2,n))
		{
			printf("%d\n",i);
			flag=1;
			break;
		}
	}
	if(!flag)	printf("-1\n");
}
