#include<iostream>
using namespace std;
int n,d[100003];
long long ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>d[i];
	for(int i=1;i<=n;++i)
		if(d[i]>d[i-1])
			ans+=d[i]-d[i-1];
	cout<<ans;
	return 0;
}
