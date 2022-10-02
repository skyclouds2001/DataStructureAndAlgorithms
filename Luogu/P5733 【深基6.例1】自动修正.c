#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char s[101]={'\0'};
	short i=0;
	scanf("%s",s);
	for(i=0;i<strlen(s);i++)
	{
		if(islower(s[i]))
		{
			s[i]=s[i]-'a'+'A';
		}
	}
	printf("%s",s);
	return 0;
 } 
