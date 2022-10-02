#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	char s[20];
	scanf("%s",s);
	int n=strlen(s),j;
	if(s[0]=='-')
	{
		cout<<'-';
		for(j=n-1;j>=1&&s[j]=='0';--j);
		for(;j>=1;--j)
			cout<<s[j];
	}
	else
	{
		for(j=n-1;j>=0&&s[j]=='0';--j);
		for(;j>=0;--j)
			cout<<s[j];
	}
	return 0;
}
