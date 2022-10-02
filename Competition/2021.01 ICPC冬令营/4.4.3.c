#include<stdio.h>
#include<math.h>
int main()
{
	double Vs=0,R=0,C=0,W=0,Vr=0;
	int n=0,i=0;
	scanf("%lf%lf%lf%d",&Vs,&R,&C,&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf",&W);
		Vr=R*C*W*Vs/sqrt(R*R*C*C*W*W+1);
		printf("%.3f\n",Vr);
	}
	return 0;
}
