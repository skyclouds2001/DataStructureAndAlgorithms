#include<stdio.h>
#include<math.h>
double a=0,b=0,c=0,d=0;
double f(double);
int main()
{
	double i=0,t=0;
	short j=0;
	double a1=0,a2=0;
	double x[3]={0};	
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	for(i=-100;i<100;i++)
	{
		if(f(i)==0)
		{
			x[j]=i;
			j++;
		}
		else if(f(i)*f(i+1)<0)
		{			
	        a1=i;  a2=i+1;
	        while(fabs(t-a1)>=0.001||fabs(a2-t)>=0.001)
	        {
		        t=(a1+a2)/2.0;
		        if(f(t)==0)  break;
		        else if(f(a1)==0)
		        {
		        	t=a1;  break;
		        }
		        else if(f(a2)==0)
		        {
		        	t=a2;  break;
		        }
		        else if(f(a1)*f(t)<0)  a2=t;
		        else  a1=t;
        	}
        	x[j]=t;
        	j++;
        }		
	}
	for(j=0;j<3;j++)
	{
		printf("%.2f ",x[j]);
	}
	return 0;
}
double f(double x)
{
	double result=0;
	result=a*pow(x,3)+b*x*x+c*x+d;
	return result;
}
