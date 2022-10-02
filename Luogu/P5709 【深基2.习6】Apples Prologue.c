#include<stdio.h>
int main()
{
	short m=0,t=0,s=0,n=0;
	scanf("%hd%hd%hd",&m,&t,&s);
	if(s==0) n=m;
	else if(t==0||(s-s%t)/t>=m) n=0;
	else
	{
		if(s%t) n=m-(s+t-s%t)/t;
		else n=m-s/t;
	}
	printf("%hd",n);
	return 0;
}
