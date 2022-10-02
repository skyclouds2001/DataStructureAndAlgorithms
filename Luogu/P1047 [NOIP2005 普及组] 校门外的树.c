#include<stdio.h>
int main()
{
	short l,m;
	short i,j;
	short count=0;
	scanf("%hd%hd",&l,&m);
	short u,v;
	short f[l+1];
	for(i=0;i<=l;i++)
	    f[i]=1;
	for(i=0;i<m;i++)
	{
		scanf("%hd%hd",&u,&v);
		for(j=u;j<=v;j++)
		{
			f[j]=0;
		}
	}    
	for(i=0;i<=l;i++)
	{
		if(f[i]==1)  count++;
	}
	printf("%hd",count);
	return 0;
 } 
