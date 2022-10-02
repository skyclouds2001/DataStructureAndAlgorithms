#include<stdio.h>
void load(long long *F)
{
	F[0]=1;	F[1]=1;
	short i=0;
	for(i=2;i<14;i++)
		F[i]=i*F[i-1];
	return;
}
int main()
{
	long long F[14]={0};
	load(F);
	int n=0;
	scanf("%d",&n);
	if(n>13||n<0&&(-n)%2==1)	printf("Overflow!");
	else if(F[n]<10000||n<0&&(-n)%2==0)	printf("Underflow!");
	else	printf("%lld",F[n]);
	return 0;
}
