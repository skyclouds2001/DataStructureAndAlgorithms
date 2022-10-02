#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int main()
{
	short al[26]={0};
	short maxn=0,minn=0,len=0;
	char s[100]={'\0'};
	_Bool isprime(short);
	short i=0;
	scanf("%s",s);
	len=strlen(s);
	for(i=0;i<len;i++)  al[s[i]-'a']++;
	for(i=0,maxn=0,minn=100;i<26;i++)
	{
		if(maxn<al[i])  maxn=al[i];
		if(al[i]!=0&&minn>al[i])  minn=al[i];
	}
	if(isprime(maxn-minn))  printf("Lucky Word\n%hd",maxn-minn);
	else  printf("No Answer\n0");
	return 0;
 } 
_Bool isprime(short x)
{
	if(x<=1)  return 0;
	else if(x==2)  return 1;
	else if(x%2==0&&x!=2)  return 0;
	else
	{
		short i=0;
		for(i=3;i<=sqrt(x);i++)
		{
			if(x%i==0)  return 0;
		}
		return 1;
	}
}
