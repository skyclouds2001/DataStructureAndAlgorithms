#include<iostream>
using namespace std;
int n,a[10005],ans; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=2,t=1;i<=n;++i)
		if(a[i]-a[i-1]==1)
			++t;
		else
			ans=max(ans,t),t=1;
	cout<<ans;
	return 0;
}
