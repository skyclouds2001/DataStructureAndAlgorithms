#include<iostream>
using namespace std;
int n,x,a[100003];
unsigned long long ans;
int main()
{
	cin>>n>>x;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i)
		if(a[i-1]+a[i]>x)
			if(a[i]<a[i]+a[i-1]-x)
				ans+=(a[i]+a[i-1]-x),a[i]=0,a[i-1]-=(a[i-1]-x);
			else
				ans+=(a[i]+a[i-1]-x),a[i]-=(a[i]+a[i-1]-x);
	cout<<ans;
	return 0;
}
