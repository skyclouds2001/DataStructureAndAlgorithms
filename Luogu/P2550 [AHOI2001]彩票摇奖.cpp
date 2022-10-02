#include<iostream>
using namespace std;
int ans[7],count,n;
bool f[40];
int main()
{
	cin>>n;
	for(int i=0,t;i<7;++i)
		cin>>t,f[t]=true;
	for(int i=1,t;i<=n;++i)
	{
		count=0;
		for(int j=0;j<7;++j)
		{
			cin>>t;
			if(f[t])
				++count;
		}
		if(count) ++ans[7-count];
	}
	for(int i=0;i<7;++i)
		cout<<ans[i]<<' ';
	return 0;
}
