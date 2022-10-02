#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char s[256]={'\0'};
	short x[3]={0},n=0;
	short i=0,j=0;
	scanf("%s",s);
	n=strlen(s);
	for(i=0;i<n;i+=5)
	{
		if(s[i]=='a') j=0;
		else if(s[i]=='b') j=1;
		else if(s[i]=='c') j=2;
		if(isdigit(s[i+3])) x[j]=s[i+3]-'0';
		else if(isalpha(s[i+3])) x[j]=x[s[i+3]-'a'];
	}
	printf("%hd %hd %hd",x[0],x[1],x[2]);
	return 0;
}
