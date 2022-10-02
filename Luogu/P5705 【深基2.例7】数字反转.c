#include<stdio.h>
#include<string.h>
int main()
{
	char num[10]={'\0'},ans[10]={'\0'};
	short i=0;
	scanf("%s",num);
	for(i=0;i<5;i++) ans[i]=num[4-i];
	printf("%s",ans);
	return 0;
}
