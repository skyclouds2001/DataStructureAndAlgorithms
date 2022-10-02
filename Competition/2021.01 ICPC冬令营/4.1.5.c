#include<stdio.h>
int main()
{
	int N=0,x[100]={0},y[100]={0},A=0,B=0,sum1=0,sum2=0;
	int i=0,j=0;
	_Bool flag=0;
	while(1)
	{
		flag=1;
		scanf("%d",&N);
		if(N==0)	break;
		for(i=0;i<N*2;i++)
			scanf("%d %d",&x[i],&y[i]);
		for(A=-500;A<=500&&flag;A++)
		{
			for(B=-500;B<=500&&flag;B++)
			{
				sum1=0;	sum2=0;
				for(i=0;i<N;i++)
				{
					j=A*x[i]+B*y[i];
					if(j==0)	break;
					else if(j<0)	sum1++;
					else if(j>0)	sum2++;
				}
				if(sum1==sum2&&i==N)
				{
					printf("%d %d\n",A,B);
					flag=0;
				}					
			}
		}
	}
	return 0;
}
