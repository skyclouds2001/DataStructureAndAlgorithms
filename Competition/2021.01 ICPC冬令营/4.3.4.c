#include<stdio.h>
#define PI 3.1415926535
int main()
{
	int N=0,n=0,m=0,t=0,c=0,s=0;
	int i=0;
	double p1=0,p2=0,p3=0,p4=0;
	scanf("%d",&N);
	for(i=0;i<N;i++)	
	{
		scanf("%d %d %d %d",&m,&n,&t,&c);
		s=m*n*t*t;
		p4=PI*(m-1.0)*(n-1.0)*c*c/4.0;
		p3=(m-1.0)*(n-1.0)*c*c-p4;
		p2=(m+n-2.0)*c*c+c*(t-c)*(2.0*m*n-m-n);
		p1=s-p2-p3-p4;
		printf("Case %d:\n"
				"Probability of covering 1 tiles = %.4f%%\n"
				"Probability of covering 2 tiles = %.4f%%\n"
				"Probability of covering 3 tiles = %.4f%%\n"
				"Probability of covering 4 tiles = %.4f%%\n\n"
				,i+1,p1/s*100,p2/s*100,p3/s*100,p4/s*100);
	}
	return 0;
}
