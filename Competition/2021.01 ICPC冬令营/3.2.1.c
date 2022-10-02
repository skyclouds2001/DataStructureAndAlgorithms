#include<stdio.h>
int f(int,int,int);
int w[21][21][21]={0};
int main()
{
	int a=0,b=0,c=0;	
	while(1)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(a==-1&&b==-1&&c==-1)	break;
		printf("%d\n",f(a,b,c));
	}
	return 0;
}
int f(int a,int b,int c)
{	
	int sum=0;
	if(a<=0||b<=0||c<=0) sum=1;
	else if(a>20||b>20||c>20)
		sum=f(20,20,20);
	else if(a<b&&b<c)
	{
		if(w[a][b][c])
			sum=w[a][b][c];
		else
			sum=f(a,b,c-1)+f(a,b-1,c-1)-f(a,b-1,c);
	}
	else
	{
		if(w[a][b][c])
			sum=w[a][b][c];
		else
			sum=f(a-1,b,c)+f(a-1,b-1,c)+f(a-1,b,c-1)-f(a-1,b-1,c-1);
	}
	w[a][b][c]=sum;
	return sum;
}
