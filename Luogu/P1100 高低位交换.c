#include<stdio.h>
int main()
{
	unsigned int n=0,a=0,b=0,ans=0;
	scanf("%d",&n);
	a=n>>16;	b=n<<16;	
	/*printf("%X %X %X %X\n",n,a,b,ans);*/
	ans=(0x0|a)|(0x0|b);
	printf("%u",ans);
	return 0;
}
/*#include<stdio.h>
union aa{
	int n;
	char s[4];
};
int main()
{
	int a=0,b=0;
	union aa o;
	o.n=1314520;
	printf("%d\n%X %X %X %X\n",o.n,o.s[0],o.s[1],o.s[2],o.s[3]);
	o.n=o.n>>8;
	printf("%d\n%X %X %X %X\n",o.n,o.s[0],o.s[1],o.s[2],o.s[3]);
	o.n=o.n>>8;
	printf("%d\n%X %X %X %X\n",o.n,o.s[0],o.s[1],o.s[2],o.s[3]);
	o.n=o.n>>8;
	printf("%d\n%X %X %X %X\n",o.n,o.s[0],o.s[1],o.s[2],o.s[3]);
	return 0;
 } */
