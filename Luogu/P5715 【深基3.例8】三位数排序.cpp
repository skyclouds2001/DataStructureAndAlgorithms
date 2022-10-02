#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	(a>b)?(swap(a,b),0):0;
	(b>c)?(swap(b,c),0):0;
	(a>b)?(swap(a,b),0):0;
	cout<<a<<' '<<b<<' '<<c;
	return 0;
}
