#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n;
double ans;
struct TIME{
	int ti,fi;
}t[1003];
bool cmp(TIME a,TIME b)
{
	return (a.ti<b.ti);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>t[i].ti,t[i].fi=i;
	sort(t+1,t+n+1,cmp);
	for(int i=1;i<=n;++i)
		cout<<t[i].fi<<' ',ans+=t[i].ti*(n-i);
	ans/=n;
	cout<<endl;
	printf("%.2f\n",ans);
	return 0;
}
