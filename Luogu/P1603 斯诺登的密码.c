#include<stdio.h>
#include<string.h>
int main()
{
	char *nums[26]={"one","two","three","four","five","six","seven","eight","nine",\
	"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen",\
	"eighteen","nineteen","twenty","a","both","another","first","second","third"};
	short numn[26]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,1,2,1,1,2,3};
	short i=0,j=0,t=0,a[6]={0},n=0;
	char s[20]={'\0'};
	for(i=0;i<6;i++)
	{
		memset(s,'\0',20*sizeof(char));
		scanf("%s",s);
		for(j=0;j<26;j++)
		{
			if(!strcmp(s,nums[j]))
			{
				a[n]=numn[j]*numn[j]%100;
				n++;
				break;
			}
		}
	}
	if(n==0)	printf("0\n");
	else
	{
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(a[j]>a[j+1])
				{
					t=a[j];		a[j]=a[j+1];	a[j+1]=t;
				}
			}
		}
		_Bool f=0;
		for(i=0;i<n;i++)
		{
			if(a[i]>=10)	printf("%d",a[i]);
			else if(a[i]<=9&&a[i]>0&&f)
				printf("0%d",a[i]);
			else if(a[i]<=9&&a[i]>0&&(!f))
			{
				printf("%d",a[i]);
				f=1;
			}
		}
		printf("\n");
	}	
	return 0;
}
