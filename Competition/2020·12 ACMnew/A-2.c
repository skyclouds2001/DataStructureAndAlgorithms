#include<stdio.h>
int main()
{
	int n=0,suma=0,sumb=0;
	scanf("%d",&n);
	int i,t;
	for(i=0;i<n;i++)  
	{
		scanf("%d",&t);
		suma+=t;
	} 
	for(i=0;i<n;i++)  
	{
		scanf("%d",&t);
		sumb+=t;
	}	
	int a[100]={0};
	void dos(int*,int,int);
	dos(a,suma,sumb);
	short flag=0;
	for(i=99;i>=0;i--)
	{
		if(a[i]!=0)  flag=1;
		if(flag==1)  printf("%hd",a[i]);
	}
	return 0;
}
void dos(int*aa,int sa,int sb)
{
	int ii=0;
	short tt;
	ii=0;
	while(sa!=0)
	{
		*(aa+ii)+=sa%10;
		sa/=10;
		ii++;
	}
	while(sb!=0)
	{
		tt=sb%10;
		ii=0;
		while(1)
		{
			if(*(aa+ii)==0)  continue;
			*(aa+ii)*=tt;
			ii++;			
			if(ii==99)  break;
		}
	}
	for(ii=0;ii<99;ii++)
	{
		while(*(aa+ii)>=10)
		{
			*(aa+ii)-=10;
			*(aa+ii+1)+=1;
		}
	}
} 
