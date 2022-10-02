#include<iostream>
#include<cstdio>
using namespace std;
int n,h[100005];
long long ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		scanf("%d",&h[i]);
	for(int i=1;i<=n;++i)
		if(h[i]>h[i-1])
			ans+=h[i]-h[i-1];
	cout<<ans;
	return 0;
}
