#include<iostream>
#include<algorithm>
#define POW(a)	((a)*(a))
using namespace std;
int n,h[500];
long long ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>h[i];
	sort(h+1,h+n+1);
	for(int i=0,j=n;i<j;)
		ans+=POW(h[j]-h[i]),++i,ans+=POW(h[i]-h[j]),--j;
	cout<<ans;
	return 0;
}
