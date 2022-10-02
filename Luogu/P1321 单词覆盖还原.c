#include<stdio.h>
#include<string.h>
int main()
{
	char s[256]={'\0'};
	short n=0,n1=0,n2=0;
	short i=0,j=0;
	gets(s);
	n=strlen(s);
	for(i=0;i<n-2;i++)
	{
		n1+=(s[i]=='b'||s[i+1]=='o'||s[i+2]=='y');
	}
	for(i=0;i<n-3;i++)
	{
		n2+=(s[i]=='g'||s[i+1]=='i'||s[i+2]=='r'||s[i+3]=='l');
	}
	printf("%hd\n%hd",n1,n2);
	return 0;
}
