#include<stdio.h>
#include<math.h>
struct point{
	double x;
	double y;
};
int main()
{
	int i=0,j=0,a=0,b=0;
	struct point p[4],t={0,0};
	_Bool flag=1;
	for(i=0;i<4;i++)	scanf("%lf%lf",&(p[i].x),&(p[i].y));
	for(i=0;i<2&&flag;i++)
	{
		for(j=2;j<4&&flag;j++)
		{
			if(p[i].x==p[j].x&&p[i].y==p[j].y)
			{
				a=i;	b=j;
				flag=0;
			}
		}
	}
	if(a==0)
	{
		t=p[0];	p[0]=p[1];	p[1]=t;
	}
	if(b==2)	p[2]=p[3];
	p[3].x=p[0].x+p[2].x-p[1].x;
	p[3].y=p[0].y+p[2].y-p[1].y;
	printf("%.3f %.3f",p[3].x,p[3].y);
	return 0;
}
