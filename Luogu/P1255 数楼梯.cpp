#include<iostream>
using namespace std;
short a[5001][1100],N;
int main()
{	
	cin>>N;
	if(N==0)
	{
		cout<<0;
		return 0;
	}
	a[1][0]=1;	a[2][0]=2;
	for(int i=3;i<=N;i++)
	{
		for(int j=0;j<1100;j++)
		{
			a[i][j]+=a[i-1][j]+a[i-2][j];
			a[i][j+1]+=a[i][j]/10;
			a[i][j]%=10;
		}
	}
	int k=1099;
	while(a[N][k]==0)	k--;
	for(;k>=0;k--)
		cout<<a[N][k];
	return 0;
}
