#include<stdio.h>
#include<string.h>
#define min(a,b) ((a<b)?a:b)
int main()
{
	int n=0,i=0,j=0,len=0;
	char num[20][15]={'\0'},ans[300]={'\0'},ls[15]={'\0'},com[2][15]={'\0'};
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%s",num[i]);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			len=min(strlen(num[j]),strlen(num[j+1]));
			if(strcmp(num[j],num[j+1])<0||strncmp(num[j],num[j+1],len)==0)
			{
				if(strncmp(num[j],num[j+1],len)==0)
				{
					strcpy(com[0],num[j]);	strcat(com[0],num[j+1]);
					strcpy(com[1],num[j+1]);	strcat(com[1],num[j]);
					if(strcmp(com[0],com[1])>0)
					{
						memset(com[0],'\0',30*sizeof(char));
						goto B;
					}
					memset(com[0],'\0',30*sizeof(char));
				}				
				strcpy(ls,num[j]);
				memset(num[j],'\0',15*sizeof(char));
				strcpy(num[j],num[j+1]);
				memset(num[j+1],'\0',15*sizeof(char));
				strcpy(num[j+1],ls);
				memset(ls,'\0',15*sizeof(char));
			}
			B: ;
		}
	}
	if(num[0][0]=='0')	printf("0");
	else
	{
		for(i=0;i<n;i++)
			printf("%s",num[i]);
	}
	return 0;
}
