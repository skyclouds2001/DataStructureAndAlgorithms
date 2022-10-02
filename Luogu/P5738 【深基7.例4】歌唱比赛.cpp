#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n=0,m=0;
	double man=0;
	cin>>n>>m;
	for(int i=0,max=0,min=20,sum=0,t=0;i<n;i++)
	{
		max=0;	min=20;
		sum=0;
		for(int j=0;j<m;j++)
		{
			cin>>t;
			sum+=t;
			if(t>max)
				max=t;
			if(t<min)
				min=t;
		}
		if(man<(double)(sum-min-max)/(m-2))	man=(double)(sum-min-max)/(m-2);
	}
	printf("%.2f",man);
	return 0;
}
