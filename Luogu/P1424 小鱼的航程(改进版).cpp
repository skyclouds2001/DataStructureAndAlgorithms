#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int x,n;
	long long d=0;
	cin>>x>>n;
	while(n>0)
	{
		if(x==6||x==7)	;
		else ++d;
		--n;
		++x;
		if(x==8)	x=1;
	}
	cout<<d*250;
	return 0;
}
