#include<iostream>
using namespace std;
int main()
{
	int a,d;
	cin>>a;
	for(d=1;a>1;++d)
		a/=2;
	cout<<d;
	return 0;
}
