#include<iostream>
#include<cstdio>
using namespace std;
struct search{
	int P;
	int C;
};
struct search S[100000];
void sort_fast(struct search *a,int l,int r)
{
	if(l>=r)  return;		
	if(l-r>20)
	{
		int i=l,j=r;
		struct search x;
		x=*(a+i);
		while(i<j)
		{		
			for(;(a+j)->P>x.P&&i<j;j--)  ;
			if(i<j)  *(a+i)=*(a+j);
			for(;(a+i)->P<=x.P&&i<j;i++)  ;
			if(i<j)  *(a+j)=*(a+i);
		}
		*(a+j)=x;
		sort_fast(a,l,i-1);
		sort_fast(a,i+1,r);
	}
	else
	{
		int i=0,j=0;
		struct search t;
		bool flag=0; 
		for(i=l;i<=r;i++)
		{
			for(j=l,flag=0;j<=r-1;j++)
			{
				if((a+j)->P>(a+j+1)->P)
				{
					t=*(a+j);  *(a+j)=*(a+j+1);  *(a+j+1)=t;  flag=1;
				}
			}
			if(!flag)  break;
		}
	}
}
int main()
{
	unsigned long long count=0;
	int n=0,m=0;
	unsigned min=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d%d",&(S[i].P),&(S[i].C));
	sort_fast(S,0,n-1);
	for(int i=0,j=0;i<n;)
	{
		min=0xFFFFFFFF;
		for(j=i;j<n&&(S[j].C)!=0;j++)
		{
			if(min>S[j].C)	min=S[j].C;
		}
		if(i==j)
		{
			while(i<n&&S[i].C==0)	i++;
		}
		else
		{
			count+=min;
			for(int k=i;k<j;k++)
				S[k].C=S[k].C-min;
		}
	}
	printf("%llu",count);
	return 0;
}
