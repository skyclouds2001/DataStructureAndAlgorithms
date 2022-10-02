#include<stdio.h>
#include<string.h>
#include<ctype.h> 
#include<stdlib.h>
struct cacu{
	int x;
	int y;
	char f;
	int len;
	int result;
};
int ilen(int a)
{
	short k=0;
	if(a<0)
	{
		a=-a;  k++;
	}
	if(a>=0&&a<=9)  k+=1;
	else if(a>=10&&a<=99)  k+=2;
	else if(a>=100&&a<=999)  k+=3;
	else if(a>=1000&&a<=9999)  k+=4;
	else if(a>=10000)  k+=5;
	return k;
}
int main()
{
	short N=0,n=0,i=0,j=0,k=0;	
	char t=0,ls[50]={'\0'};
	scanf("%hd",&N);  getchar();
	struct cacu s[N];
	for(i=0,j=0;i<N;i++,j=0)
	{
		while(ls[j]=getchar(),isalnum(ls[j])||ls[j]==' ') j++; 
		ls[j]='\0';
		n=strlen(ls);
		k=0;
		if(isalpha(ls[0]))
		{
			switch(ls[0])
			{
				case 'a':t='+';s[i].f=t;break;
				case 'b':t='-';s[i].f=t;break;
				case 'c':t='*';s[i].f=t;break;
			}
			j=2;
		}
		else if(isdigit(ls[0]))
		{
			j=0;
			s[i].f=t;
		}
		while(isdigit(ls[j]))
		{
			k*=10;
			k+=(ls[j]-'0');
			j++;
		}
		s[i].x=k;
		k=0;
		j++;
		while(isdigit(ls[j]))
		{
			k*=10;
			k+=(ls[j]-'0');
			j++;
		}
		s[i].y=k;
		switch(t)
		{
			case '+': s[i].result=s[i].x+s[i].y;break;
			case '-': s[i].result=s[i].x-s[i].y;break;
			case '*': s[i].result=s[i].x*s[i].y;break;
		}
		s[i].len=ilen(s[i].result)+ilen(s[i].x)+ilen(s[i].y)+2;
		memset(ls,'\0',sizeof(char));
	}	
	for(i=0;i<N;i++)
		printf("%d%c%d=%d\n%d\n",s[i].x,s[i].f,s[i].y,s[i].result,s[i].len);
	return 0;
}
