#include<iostream>
#include<stack>
using namespace std;
int n,a[3000000+3],ans[3000000+3];
stack<int> S;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i)
	{
		while(not S.empty() and a[S.top()]<a[i])
			ans[S.top()]=i,S.pop();
		S.push(i);
	}
	for(int i=1;i<=n;++i)
		cout<<ans[i]<<' ';
	return 0;
}
