#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char word[11]={'\0'},title[1000001]={'\0'};
	int n=0,N=0,i=0;
	int count=0,k=0;
	gets(word);
	gets(title);
	N=strlen(word);
	n=strlen(title);
	for(i=0;i<N;i++)
	{
		if(isupper(word[i]))  word[i]=word[i]-'A'+'a';
	}
	for(i=0;i<n;i++)
	{
		if(isupper(title[i]))  title[i]=title[i]-'A'+'a';
	}
	for(i=0;i<n-N;i++)
	{
		if(!strncmp(word,title+i,N)&&(i==n-N||title[i+N]==' ')&&(i==0||title[i-1]==' '))
		{
			count++;
			if(count==1)  k=i;
		}
	}
	if(count==0)  printf("-1");
	else  printf("%d %d",count,k);
	return 0;
}
