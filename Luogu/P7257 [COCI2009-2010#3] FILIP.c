#include<stdio.h>
int main()
{
	int a=0,b=0;
	int aa[3]={0},bb[3]={0};
	scanf("%d%d",&a,&b);
	aa[0]=a/100;	bb[0]=b/100;
	aa[1]=a/10%10;	bb[1]=b/10%10;
	aa[2]=a%10;		bb[2]=b%10;
	a=aa[0]+aa[1]*10+aa[2]*100;
	b=bb[0]+bb[1]*10+bb[2]*100;
	printf("%d",(a>b)?a:b);
	return 0;
 } 
