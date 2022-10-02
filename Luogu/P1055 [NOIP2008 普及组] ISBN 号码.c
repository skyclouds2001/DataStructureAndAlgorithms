#include<stdio.h>
int main()
{
	char isbn[15]={'\0'};
	int sum=0;
	scanf("%s",isbn);
	sum=(isbn[0]-'0')+(isbn[2]-'0')*2+(isbn[3]-'0')*3+(isbn[4]-'0')*4\
	+(isbn[6]-'0')*5+(isbn[7]-'0')*6+(isbn[8]-'0')*7+(isbn[9]-'0')*8\
	+(isbn[10]-'0')*9;
	sum%=11;
	if(sum<10)
	{
		if(sum==isbn[12]-'0')	printf("Right");
		else
		{
			isbn[12]='\0';
			printf("%s%d",isbn,sum);
		}
	}
	else if(sum==10)
	{
		if(isbn[12]=='X')	printf("Right");
		else
		{
			isbn[12]='\0';
			printf("%sX",isbn);
		}
	}
	return 0;
}
