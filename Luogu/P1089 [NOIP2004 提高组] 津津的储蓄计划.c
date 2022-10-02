#include<stdio.h>
int main()
{
	short a[12]={0};
	short jj=0,mm=0;
	short i;
	for(i=0;i<12;i++)
	    scanf("%hd",&a[i]);
	for(i=0;i<12;i++)
	{
		jj+=300;
		jj-=a[i];
		while(jj>=100)
		{
			jj-=100;
			mm+=100;
		}
		if(jj<0)
		{
			printf("-%hd",i+1);
			break;
		}
	}
	if(i==12)
	{
		printf("%hd",(jj+(short)((float)mm*1.2)));
	}
	return 0;
} 
