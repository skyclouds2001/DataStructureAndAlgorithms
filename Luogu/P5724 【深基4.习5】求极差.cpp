#include<iostream>
using namespace std;
int main()
{
	int n,ma=0,mi=10000;
	cin>>n;
	for(int i=1,t;i<=n;++i)
		cin>>t,ma=max(ma,t),mi=min(mi,t);
	cout<<ma-mi<<endl;
	return 0;
}
