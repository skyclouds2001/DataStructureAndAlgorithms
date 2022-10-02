#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char s[30]={'\0'};
	char t=0,ls[30]={'\0'};
	int isword(char*);
	int isbig(char);
	while(scanf("%s",s)!=EOF)
	{
		if(isword(s))
		{
			if(isbig(s[0]))
			{
				strcat(s,"ay");
			}
			else
			{
				t=s[0];
				strcpy(s,s+1);
				s[strlen(s)]=t;
				strcat(s,"ay");
			}
		}
		printf("%s\n",s);
		memset(s,'\0',30*sizeof(char));
	}	
	return 0;
}
int isword(char* p)
{
	int n=strlen(p),i;
	for(i=0;i<n;i++)
	{
		if(!isalpha(p[i])) return 0;
	}
	return 1;
}
int isbig(char t)
{
	if(t=='a'||t=='e'||t=='i'||t=='o'||t=='u'||\
	t=='A'||t=='E'||t=='I'||t=='O'||t=='U')
		return 1;
	else	return 0;
}
