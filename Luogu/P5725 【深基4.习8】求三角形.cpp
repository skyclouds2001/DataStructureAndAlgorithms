#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(i*n+j-n<10)
				cout<<'0'<<i*n+j-n;
			else
				cout<<i*n+j-n;
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=1,t=1;i<=n;++i)
	{
		for(int j=1;j<=n-i;++j)
		{
			cout<<"  ";
		}
		for(int j=n-i+1;j<=n;++j)
		{
			if(t<10)
				cout<<'0'<<t;
			else
				cout<<t;
			++t;
		}
		cout<<endl;
	}
	return 0;
}
