#include<stdio.h>
int main()
{
	short height[10]={0};
	short length=0,*p=height,count=0;
	scanf("%hd%hd%hd%hd%hd%hd%hd%hd%hd%hd",p,p+1,p+2,p+3,p+4,p+5,p+6,p+7,p+8,p+9);
	scanf("%hd",&length);
	short i;
	for(i=0;i<10;i++)
	{
		if(height[i]<=length) count++;
		else if(height[i]<=length+30) count++; 
	}
	printf("%d",count);
	return 0;
}
