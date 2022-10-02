#include<stdio.h>
#include<string.h>
int main()
{
	int n=0,i=0,j=0;
	scanf("%d",&n);	getchar();
	char s[n][n];	_Bool f[n][n];
	void f1(_Bool*,char*,int);
	void f2(_Bool*,char*,int);
	void f3(_Bool*,char*,int);
	void f4(_Bool*,char*,int);
	void f5(_Bool*,char*,int);
	void f6(_Bool*,char*,int);
	void f7(_Bool*,char*,int);
	void f8(_Bool*,char*,int);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)	f[i][j]=0;
		scanf("%s",s[i]);
		if(i!=n-1) getchar();
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(s[i][j]=='y')
			{
				if(j<=n-7)	f1(f[i]+j,s[i]+j,n);
				if(i<=n-7)	f2(f[i]+j,s[i]+j,n);
				if(j>=6)	f3(f[i]+j,s[i]+j,n);
				if(i>=6)	f4(f[i]+j,s[i]+j,n);
				if(j<=n-7&&i<=n-7)	f5(f[i]+j,s[i]+j,n);
				if(j>=6&&i<=n-7)	f6(f[i]+j,s[i]+j,n);
				if(j>=6&&i>=6)	f7(f[i]+j,s[i]+j,n);
				if(i>=6&&j<=n-7)	f8(f[i]+j,s[i]+j,n);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(f[i][j])	printf("%c",s[i][j]);
			else	printf("*");
		}
		printf("\n");
	}
	return 0;
}
void f1(_Bool *f,char *si,int n)
{
	if(*(si+1)=='i'&&*(si+2)=='z'&&*(si+3)=='h'\
	&&*(si+4)=='o'&&*(si+5)=='n'&&*(si+6)=='g')
	{
		*f=1;
		*(f+1)=1;	*(f+2)=1;	*(f+3)=1;
		*(f+4)=1;	*(f+5)=1;	*(f+6)=1;
	}
}
void f2(_Bool *f,char *si,int n)
{
	if(*(si+n)=='i'&&*(si+2*n)=='z'&&*(si+3*n)=='h'\
	&&*(si+4*n)=='o'&&*(si+5*n)=='n'&&*(si+6*n)=='g')
	{
		*f=1;
		*(f+n)=1;	*(f+2*n)=1;	*(f+3*n)=1;
		*(f+4*n)=1;	*(f+5*n)=1;	*(f+6*n)=1;
	}
}
void f3(_Bool *f,char *si,int n)
{
	if(*(si-1)=='i'&&*(si-2)=='z'&&*(si-3)=='h'\
	&&*(si-4)=='o'&&*(si-5)=='n'&&*(si-6)=='g')
	{
		*f=1;
		*(f-1)=1;	*(f-2)=1;	*(f-3)=1;
		*(f-4)=1;	*(f-5)=1;	*(f-6)=1;
	}
}
void f4(_Bool *f,char *si,int n)
{
	if(*(si-n)=='i'&&*(si-2*n)=='z'&&*(si-3*n)=='h'\
	&&*(si-4*n)=='o'&&*(si-5*n)=='n'&&*(si-6*n)=='g')
	{
		*f=1;
		*(f-n)=1;	*(f-2*n)=1;	*(f-3*n)=1;
		*(f-4*n)=1;	*(f-5*n)=1;	*(f-6*n)=1;
	}
}
void f5(_Bool *f,char *si,int n)
{
	if(*(si+n+1)=='i'&&*(si+2*n+2)=='z'&&*(si+3*n+3)=='h'\
	&&*(si+4*n+4)=='o'&&*(si+5*n+5)=='n'&&*(si+6*n+6)=='g')
	{
		*f=1;
		*(f+n+1)=1;	*(f+2*n+2)=1;	*(f+3*n+3)=1;
		*(f+4*n+4)=1;	*(f+5*n+5)=1;	*(f+6*n+6)=1;
	}
}
void f6(_Bool *f,char *si,int n)
{
	if(*(si+n-1)=='i'&&*(si+2*n-2)=='z'&&*(si+3*n-3)=='h'\
	&&*(si+4*n-4)=='o'&&*(si+5*n-5)=='n'&&*(si+6*n-6)=='g')
	{
		*f=1;
		*(f+n-1)=1;	*(f+2*n-2)=1;	*(f+3*n-3)=1;
		*(f+4*n-4)=1;	*(f+5*n-5)=1;	*(f+6*n-6)=1;
	}
}
void f7(_Bool *f,char *si,int n)
{
	if(*(si-n-1)=='i'&&*(si-2*n-2)=='z'&&*(si-3*n-3)=='h'\
	&&*(si-4*n-4)=='o'&&*(si-5*n-5)=='n'&&*(si-6*n-6)=='g')
	{
		*f=1;
		*(f-n-1)=1;	*(f-2*n-2)=1;	*(f-3*n-3)=1;
		*(f-4*n-4)=1;	*(f-5*n-5)=1;	*(f-6*n-6)=1;
	}
}
void f8(_Bool *f,char *si,int n)
{
	if(*(si-n+1)=='i'&&*(si-2*n+2)=='z'&&*(si-3*n+3)=='h'\
	&&*(si-4*n+4)=='o'&&*(si-5*n+5)=='n'&&*(si-6*n+6)=='g')
	{
		*f=1;
		*(f-n+1)=1;	*(f-2*n+2)=1;	*(f-3*n+3)=1;
		*(f-4*n+4)=1;	*(f-5*n+5)=1;	*(f-6*n+6)=1;
	}
}
