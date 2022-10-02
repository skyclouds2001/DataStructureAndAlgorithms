#include<stdio.h>
short f(short t,short k)
{
	short sum=0;
	while(t)
	{
		sum+=t%k;
		t/=k;
	}
	return sum;
}
int main()
{
	short i=0;
	short t=0;
	for(i=2992;i<10000;i++)
	{
		t=f(i,10);
		if(t==f(i,12)&&t==f(i,16))
			printf("%hd\n",i);
	}
	return 0;
}
