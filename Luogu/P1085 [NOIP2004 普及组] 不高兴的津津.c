#include<stdio.h>
int main()
{
	short a[7]={0},b[7]={0},u[7]={0};
	short uhp=0,max=0,maxi=0;
	short i;
	for(i=0;i<7;i++)
	    scanf("%hd%hd",&a[i],&b[i]);
	for(i=0;i<7;i++)
	{
		if(a[i]+b[i]>8)
			uhp+=a[i]+b[i]-8;		
		u[i]=uhp;
		uhp=0;
	}
	for(i=0,max=u[0],maxi=0;i<7;i++)
	{
		if(u[i]>max)
		{
			max=u[i];
			maxi=i;
		}
	}
	if(max==0)
	    printf("%d \n",0);
	else
	    printf("%hd \n",maxi+1);
	return 0;
}
