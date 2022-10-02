#include<iostream>
using namespace std;
int main()
{
	int n,x;
	long long ans=0;
	cin>>n>>x;
	for(int i=1,t=1;i<=n;++i,t=i)
		while(t>0)
			if(t%10==x)
				++ans,t/=10;
			else
				t/=10;
	cout<<ans;
	return 0;
}
