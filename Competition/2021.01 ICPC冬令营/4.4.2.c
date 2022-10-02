#include<stdio.h>
int main()
{
	int n=0,Vt=0,V0=0;
	double nn=0;
	while(1)
	{
		scanf("%d%d",&Vt,&V0);
		if(Vt==0&&V0==0)	break;
		if(Vt<=V0)	n=0;
		else if(Vt<=V0*2)	n=1;
		else
		{
			nn=Vt/(V0*2.0);
			n=(int)nn;
			if(nn-n==0.500000)	n=0;
			else if(nn-n>0.500000)	n++;
			else if(nn-n<0.500000)	;
		}
		printf("%d\n",n);
	}
	return 0;
}
