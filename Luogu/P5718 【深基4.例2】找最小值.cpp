#include<iostream>
using namespace std;
int main()
{
	int n,min=0x7fffffff;
	cin>>n;
	for(int i=1,t;i<=n;++i)
		cin>>t,(t<min)?(min=t):0;
	cout<<min;
	return 0;
}
