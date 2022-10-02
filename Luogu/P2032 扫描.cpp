#include<iostream>
#include<deque>
using namespace std;
int n,k,a[2000000+4];
deque<int> d;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i)
	{
		if(!d.empty() and i-d.front()>=k)
			d.pop_front();
		while(!d.empty() and a[d.back()]<a[i])
			d.pop_back();
		d.push_back(i);
		if(i>=k)
			cout<<a[d.front()]<<endl;
	}
	return 0;
}
