#include<stdio.h>
int main()
{
	int n=0;
	scanf("%d",&n);
	short Ai[n];
	short Bi[n];
	int i,j,t;
	for(i=0;i<n;i++)  scanf("%hd",Ai+i);
	for(i=0;i<n;i++)  scanf("%hd",Bi+i);
	short a[100]={0};
	void dos(short*,int);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			t=Ai[i]*Bi[j];
			dos(a,t);
		}
	}
	short flag=0;
	for(i=99;i>=0;i--)
	{
		if(a[i]!=0)  flag=1;
		if(flag==1)  printf("%hd",a[i]);
	}
	return 0;
}
void dos(short*aa,int tt)
{
	short ii=0;
	while(tt!=0)
	{
		*(aa+ii)+=tt%10;
		tt/=10;
		ii++;
	}
	for(ii=0;ii<99;ii++)
	{
		if(*(aa+ii)>=10)
		{
			*(aa+ii)-=10;
			*(aa+ii+1)+=1;
		}
	}
} 
