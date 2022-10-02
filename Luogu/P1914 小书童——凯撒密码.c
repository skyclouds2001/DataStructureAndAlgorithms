#include<stdio.h>
#include<string.h>
int main()
{
	char s[51]={'\0'};
	short f[51]={0},N=0,i=0;
	int n=0;
	scanf("%d",&n);
	scanf("%s",s);
	N=strlen(s);
	if(n>=26)  n%=26;
	for(i=0;i<N;i++)
	{
		f[i]=s[i]-'a'+1;
		f[i]+=n;
		if(f[i]>26) f[i]=(f[i]-1)%26+1;
		s[i]=f[i]-1+'a';
	}
	printf("%s",s);
	return 0;
 } 
