#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	int y,m;
	cin>>y>>m;
	if(m==2)
	{
		if(y%400==0||y%4==0&&y%100!=0)
			cout<<29;
		else
			cout<<28;
	}
	else
		cout<<a[m];
	return 0;
}
