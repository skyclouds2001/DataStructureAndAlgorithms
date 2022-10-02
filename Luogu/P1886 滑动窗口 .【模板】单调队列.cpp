#include<iostream>
#include<deque>
using namespace std;
int a[1000000+4],n,k;
int ax[1000000+4],an[1000000+4];
deque<int> dx,dn;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i)
	{
		if(!dn.empty() and i-dn.front()>=k)
			dn.pop_front();
		while(!dn.empty() and a[dn.back()]>a[i])
			dn.pop_back();
		dn.push_back(i);
		if(i>=k)
			an[i-k+1]=a[dn.front()];
		if(!dx.empty() and i-dx.front()>=k)
			dx.pop_front();
		while(!dx.empty() and a[dx.back()]<a[i])
			dx.pop_back();
		dx.push_back(i);
		if(i>=k)
			ax[i-k+1]=a[dx.front()];
	}
	for(int i=1;i<=n-k+1;++i)
		cout<<an[i]<<' ';
	cout<<endl;
	for(int i=1;i<=n-k+1;++i)
		cout<<ax[i]<<' ';
	cout<<endl;
	return 0;
}
