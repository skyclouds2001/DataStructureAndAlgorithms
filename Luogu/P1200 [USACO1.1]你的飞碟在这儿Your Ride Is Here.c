#include<stdio.h>
#include<string.h>
int main()
{
	char team[7]={'\0'},star[7]={'\0'};
	int nt=1,ns=1;
	short i=0;
	scanf("%s",star);
	scanf("%s",team);
	for(i=0;i<strlen(team);i++) nt*=(team[i]-'A'+1);
	for(i=0;i<strlen(star);i++) ns*=(star[i]-'A'+1);
	if(nt%47==ns%47) printf("GO");
	else printf("STAY");
	return 0;
}
