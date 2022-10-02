#include<stdio.h>
#include<string.h>
#include<ctype.h>
char file[2000]={'\0'};
char com[200]={'\0'};
char ls[200]={'\0'};

int main()
{	
	int q=0,i=0,f=0;
	void f1(void); void f2(void);
	void f3(void); void f4(void);
	scanf("%d",&q);
	scanf("%s",file);
	for(i=0;i<q;i++)
	{
		scanf("%d",&f);
		switch(f)
		{
			case 1:f1();break;
			case 2:f2();break;
			case 3:f3();break;
			case 4:f4();break;
		}
	}
	return 0;
}

void f1(void)
{	
	scanf("%s",com);
	strcat(file,com);
	printf("%s\n",file);
}

void f2(void)
{	
	int a=0,b=0;
	scanf("%d %d",&a,&b);
	strncpy(ls,file+a,b);
	strcpy(file,ls);
	printf("%s\n",file);
	memset(ls,'\0',200*sizeof(char));
}

void f3(void)
{
	int a=0;
	scanf("%d %s",&a,com);
	strcpy(ls,file+a);
	strcpy(file+a,com);
	strcat(file,ls);
	printf("%s\n",file);
	memset(ls,'\0',200*sizeof(char));
}

void f4(void)
{
	scanf("%s",com);
	int N=strlen(file),n=strlen(com),i=0;
	bool flag=0;
	for(i=0;i<N-n+1;i++)
	{
		if(!strncmp(file+i,com,n))
		{
			printf("%d\n",i);
			flag=1;
			break;
		}
	}
	if(!flag)	printf("-1\n");
}
