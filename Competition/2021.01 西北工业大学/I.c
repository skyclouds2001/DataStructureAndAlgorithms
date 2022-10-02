#include<stdio.h>
int main()
{
	int a=0,b=0,k=0;
	scanf("%d%d%d",&a,&b,&k);
	int i=0,p=0;
    p=k%5;
    if(p==1)  
		printf("%.8f",(double)a);
	else if(p==2)
		printf("%.8f",(double)b);
	else if(p==3)
		printf("%.8f",(1+(double)b)/(double)a);
	else if(p==4)
		printf("%.8f",((double)b+(double)a+1)/(double)a/(double)b);
	else if(p==0)
		printf("%.8f",(1+(double)a)/(double)b);
	return 0;
}
