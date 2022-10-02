#include<iostream>
using namespace std;
int main()
{
	int k;
	long long n=0;
	cin>>k;
	int i=1,t=1,kk=1;
	while(i<=k)
	{
		n+=kk;
		--t;
		if(t==0)
			++kk,t=kk;
		++i;
	}
	cout<<n;
	return 0;
}
