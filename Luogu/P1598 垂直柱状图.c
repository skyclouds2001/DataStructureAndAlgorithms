#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char s[4][200]={'\0'};
	short i=0,j=0,t=0;
	int count[26]={0},max=0;
	for(i=0;i<4;i++)
	{
		gets(s[i]);
		t=strlen(s[i]);
		for(j=0;j<t;j++)
		{
			if(isupper(s[i][j])) count[s[i][j]-'A']++;
		}
	}
	for(i=0;i<26;i++)
	{
		if(max<count[i])  max=count[i];
	}
	for(i=0;i<max;i++)
	{
		for(j=0;j<26;j++)
		{
			if(count[j]>=max-i) printf("*");
			else printf(" ");
			if(j==25) printf("\n");
			else printf(" ");
		}
	}
	for(i=0;i<26;i++)
	{
		if(i==25) printf("%c",'A'+i);
		else printf("%c ",'A'+i);
	}
	return 0;
}
