#include<stdio.h> 
int num[20000],d[20000];
int main()
{
	int b=0,s=0,m=0,di=0,dj=0,mi=0,mj=0;
	int i=0,j=0;
	scanf("%d",&b);
	for(i=0;i<b;i++)
	{
		scanf("%d",&s);
		for(j=0;j<s-1;j++)
			scanf("%d",&num[j]);
		d[0]=num[0];	m=d[0];
		di=0;	dj=0;
		mi=0;	mj=0;
		for(j=1;j<s-1;j++)
		{
			if(d[j-1]>=0)
			{
				d[j]=d[j-1]+num[j];
				dj=j+2;
			}
			else
			{
				d[j]=num[j];
				di=j+1;	dj=j+2;
			}
			if(d[j]>m||d[j]==m&&dj-di>mj-mi||d[j]==m&&dj-di==mj-mi&&di<mi)
			{
				m=d[j];
				mi=di;	mj=dj;
			}
		}
		if(m<=0)	printf("Route %d has no nice parts\n",i+1);
		else	printf("The nicest part of route %d is between stops %d and %d\n",\
						i+1,mi,mj);
	}
	return 0;
}

/*
Sample Input 		Output for the Sample Input
3 					The nicest part of route 1 is between stops 2 and 3
3 					The nicest part of route 2 is between stops 3 and 9
 -1  				Route 3 has no nice parts
 6
10
 4
 -5
 4
 -3
 4
 4
 -4
 4
 -5
4
 -2
 -3
 -4 
*/ 
