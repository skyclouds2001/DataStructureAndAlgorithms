#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int GCD(int a,int b)
{
	if(a==0)	return b;
	else	return GCD(b%a,a);
}
int main()
{
	char s[100]={'\0'};
	int i=0;
	int a=0,b=0,g=0,k=0,n=0,num=0,fz=0,fm=0,fzmin=0,fmmin=0;
	while(1)
	{
		fzmin=0x0FFFFFFF;	fmmin=0x0FFFFFFF;
		gets(s);
		if(strlen(s)==1&&s[0]=='0')	break;
		num=atoi(s+2);
		for(n=0;isdigit(*(s+2+n));n++);
		for(k=1;k<=n;k++)
		{
			a=num;	b=num;
			i=k;
			while(i)
			{
				b/=10;
				i--;
			}
			fz=a-b;
			fm=0;
			i=1;
			while(i<=n)
			{
				fm*=10;
				if(i<=k)	fm+=9;
				i++;
			}
			g=GCD(fz,fm);
			fz/=g;	fm/=g;
			if(fm<fmmin)
			{
				fzmin=fz;	fmmin=fm;
			}
		}
		printf("%d/%d\n",fzmin,fmmin);
		memset(s,'\0',100*sizeof(char));		
	}
	return 0;
}
