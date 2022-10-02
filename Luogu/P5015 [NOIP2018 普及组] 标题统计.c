#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	short n=0,i=0;
	int count=0;
	char t=0,s[1000]={'\0'};
	gets(s);
	n=strlen(s);
	for(i=0;i<n;i++)
	{
		if(isdigit(s[i])||isalpha(s[i]))  count++;
	}
	printf("%d",count++);
	return 0;
}
