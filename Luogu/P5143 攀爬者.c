#include<stdio.h>
#include<math.h>
typedef struct point{
	int x;
	int y;
	int z;
}POINT;
void sort(POINT *a,int p,int q)
{
	if(p>=q)	return;
	else
	{
		int i=p,j=q;
		POINT x=*(a+i);
		while(i<j)
		{
			for(;i<j&&x.z<(a+j)->z;j--);
			if(i<j)	*(a+i)=*(a+j);
			for(;i<j&&x.z>=(a+i)->z;i++);
			if(i<j)	*(a+j)=*(a+i);
		}
		*(a+i)=x;
		sort(a,p,i-1);
		sort(a,i+1,q);
	}
}
int main()
{
	int N=0;
	int i=0;
	double d=0;
	scanf("%d",&N);
	POINT p[N];
	for(i=0;i<N;i++)
		scanf("%d%d%d",&(p[i].x),&(p[i].y),&(p[i].z));
	sort(p,0,N-1);
	for(i=0;i<N-1;i++)
		d+=sqrt(pow(p[i+1].x-p[i].x,2)+pow(p[i+1].y-p[i].y,2)+pow(p[i+1].z-p[i].z,2));
	printf("%.3f",d);
	return 0;
}
