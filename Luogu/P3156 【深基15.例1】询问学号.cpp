#include<iostream>
using namespace std;
int n,m,a[2000005];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1,t;i<=m;++i)
		cin>>t,cout<<a[t]<<endl;
	return 0;
}
