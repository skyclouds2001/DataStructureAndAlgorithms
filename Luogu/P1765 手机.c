#include<stdio.h>
#include<string.h>
int main()
{
	short a[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
	char s[500]={'\0'};
	short n=0,i=0;
	int count=0;
	gets(s);
	n=strlen(s);
	for(i=0;i<n;i++)
	{
		if(s[i]==' ')  count++;
		else  count+=a[s[i]-'a'];
	}
	printf("%d",count);
	return 0;
 } 
