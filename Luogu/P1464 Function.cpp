#include<stdio.h>
long long f(long long,long long,long long);
long long w[21][21][21];
int main()
{
	long long a,b,c;
	while(1)
	{
		scanf("%lld %lld %lld",&a,&b,&c);
		if(a==-1&&b==-1&&c==-1)	break;
		printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,f(a,b,c));
	}
	return 0;
}
long long f(long long a,long long b,long long c)
{	
	long long sum=0;
	if(a<=0||b<=0||c<=0) return 1;
	else if(a>20||b>20||c>20)
		return f(20,20,20);
	else if(w[a][b][c])
		return w[a][b][c];
	else if(a<b&&b<c)
		sum=f(a,b,c-1)+f(a,b-1,c-1)-f(a,b-1,c);
	else
		sum=f(a-1,b,c)+f(a-1,b-1,c)+f(a-1,b,c-1)-f(a-1,b-1,c-1);
	w[a][b][c]=sum;
	return sum;
}
