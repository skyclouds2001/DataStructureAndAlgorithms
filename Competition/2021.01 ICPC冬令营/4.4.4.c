#include<stdio.h>
#include<math.h>
#define min(a,b) ((a<b)?a:b)
int main()
{
	double W=0,L=0;
	double maxx=0,minxmax=0;
	while((scanf("%lf%lf",&W,&L))!=EOF)
	{
		minxmax=min(W/2.0,L/2.0);
		maxx=((L+W)-sqrt(L*L-L*W+W*W))/6.0;
		printf("%.3f 0.000 %.3f\n",maxx,minxmax);
	}
	return 0;
}
/*
Sample Input: 
1 1 
2 2 
3 3
 
Sample Output: 
0.167 0.000 0.500 
0.333 0.000 1.000 
0.500 0.000 1.500 
*/
