#include<stdio.h>
int main()
{
	short a=0,b=0,c=0,d=0;
	short e=0,f=0;
	scanf("%hd%hd%hd%hd",&a,&b,&c,&d);
	if(b>d)
	{
		d+=60;
		c--;
	}
	e=c-a;
	f=d-b;
	printf("%hd %hd",e,f);
	return 0;
}
