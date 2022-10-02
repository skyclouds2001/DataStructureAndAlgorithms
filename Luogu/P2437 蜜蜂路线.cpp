#include<iostream>
#include<cstdio>
using namespace std;
short ff[1005][215];
short m,n;
void f(int x)
{
	ff[0][0]=1;
	ff[1][0]=1;
	for(int i=2;i<=x;i++)
	{
		for(int j=0;j<=210;j++)
		{
			ff[i][j]+=ff[i-1][j]+ff[i-2][j];
			ff[i][j+1]+=ff[i][j]/10;
			ff[i][j]%=10;
		}
	}
}
void out(int x)
{
	f(x);
	int j=210;
	while(ff[x][j]==0)	j--;
	for(;j>=0;j--)
		printf("%hd",ff[x][j]);
}
int main()
{
	cin>>m>>n;
	out(n-m);
	return 0;
}
