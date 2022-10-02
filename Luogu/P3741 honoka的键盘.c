#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
	short n=0,count=0,i;
	char s[200]={'\0'};
	scanf("%hd",&n);
	scanf("%s",s);
	if(n==1) count=0;
	else
	{
		for(i=0;i<n-1;i++)
		{
			if(!strncmp(s+i,"VK",2)) count++;
		}
	}
	if(s[0]=='K'&&s[1]=='K') count++;
	else if(s[n-2]=='V'&&s[n-1]=='V') count++;
	else
	{
		for(i=1;i<n-1;i++)
		{
			if(s[i-1]=='K'&&s[i]=='K'&&s[i+1]=='K')  {count++;break;}
			if(s[i-1]=='V'&&s[i]=='V'&&s[i+1]=='V')  {count++;break;}
		}
	}
	printf("%hd",count);
	return 0;
}
