#include<stdio.h>
int GCD(int a,int b)
{
	if(a==0)	return b;
	else	return GCD(b%a,a);
}
/*int GCD(int a,int b)
{
	if(b==0)	return a;
	else	return GCD(b,a%b);
}*/
int main()
{
	int a[1000]={0},n=0,d=0;
	int i=0,j=0;
	do
	{
		n=0;
		while(1)
		{
			scanf("%d",&a[n]);
			if(a[n]==0)	break;
			n++;
		}
		if(n==0)	break;
		for(i=0;i<n-1;i++)
			a[i]=a[i]-a[i+1];
		d=a[0];
		for(i=1;i<n-1;i++)
			d=GCD((a[i]==0)?d:a[i],d);
		printf("%d\n",d>0?d:-d);			
	}while(1);
	return 0;
}
/*
701 1059 1417 2312 0
14 23 17 32 122 0
14 -22 17 -31 -124 0
0
179
3
3
*/
