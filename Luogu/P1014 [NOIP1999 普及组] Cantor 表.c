#include<stdio.h>
int main()
{
	int N=0;
	int i=0,j=0,t=0;
	short flag=0;
	scanf("%d",&N);
	if(N==1)  
	    printf("1/1");
	else if(N==2)
	    printf("1/2");
	else if(N==3)
	    printf("2/1");
	else if(N>3)
	{
		flag=1;
		i=3;  j=1;
		for(t=4;t<N;t++)
		{
			if(flag==1&&i==1)
			{
				j++;
				flag=-1;
			}
			else if(flag==-1&&j==1)
			{
				i++;
				flag=1;
			}
			else if(flag==1)
			{
				i--;
				j++;
			}
			else if(flag==-1)
			{
				j--;
				i++;
			}
		}
		printf("%d/%d",i,j);
	}
	return 0;
 } 
