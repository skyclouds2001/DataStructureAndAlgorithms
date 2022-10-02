#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char s[100]={'\0'},*p=0;
	short n=0,flag=0,k=0;
	scanf("%s",s);
	n=strlen(s);
	short f(char*,short);
	void ff(char*,short,short);
	short search(char*,char,short);
	void clear0(char*,char*);
	flag=f(s,n);
	switch(flag)
	{
		case 1:ff(s,0,n);clear0(s,s+n);break;		
		case 3:(k=search(s,'/',n));ff(s,0,k);ff(s,k+1,n);clear0(s+k+1,s+n);clear0(s,s+n);break;
		case 4:ff(s,0,n-1);clear0(s,s+n);break;
		case 2:
		{
			k=search(s,'.',n);
			ff(s,0,k);  ff(s,k+1,n);			
			if(k==n-2&&s[n-1]=='0')  ;
			else
			{
				char*p=s+n-1;
				while(*p=='0'&&*(p-1)!='.')
				{
					*p='\0';
					p--;
				}
			}
			clear0(s,s+n);
			p=s;
			break;
		}
	}
	printf("%s",s);
	return 0;
} 

short f(char* p,short n)
{
	if(*(p+n-1)=='%')  return 4;
	short i=0;	
	for(i=0;i<n;i++)
	{
		if(*(p+i)=='.')  return 2;
		else if(*(p+i)=='/')  return 3;
	}
	return 1;
}

void ff(char*p,short l,short r)
{
	char ls[r-l];
	short i=0;
	for(i=0;i<r-l;i++)  ls[r-l-i-1]=*(p+i+l);
	strncpy(p+l,ls,r-l);
}

short search(char*p,char t,short n)
{
	short i=0;
	for(i=0;i<n;i++)
	{
		if(*(p+i)==t)  return i;
	}
	return n;
}

void clear0(char*l,char*r)
{
	char*p=0;
	short k=0,i=0;
	for(p=l;p<r;p++)
	{
		if(*p=='0')  k++;
		else  break;
	}
	if(p==r)
	{
		p=l;
		for(i=1;i<r-l;i++)  *(p+i)='\0';
	}
	else if(*p=='.'||*p=='/')
	{
		p=l;
		for(i=0;i<r-l;i++)
		{
			*(p+i)=*(p+i+k-1);
		}
	}
	else if(*p=='%')
	{
		p=l;
		for(i=0;i<r-l;i++)
		{
			*(p+i)=*(p+i+k-1);
		}
	}
	else
	{
		for(i=0,p=l;i<r-l;i++)
		{
			*(p+i)=*(p+i+k);
		}
		for(i=r-l-k;i<r-l;i++)
		{
			*(p+i)='\0';
		}
	}	
}
