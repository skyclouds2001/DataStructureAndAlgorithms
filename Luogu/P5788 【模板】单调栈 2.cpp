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
	for(int i=n;i>=1;--i)
	{
		while(not S.empty() and a[S.top()]<=a[i])
			S.pop();
		ans[i]=S.empty()?0:S.top();
		S.push(i);
	}
	for(int i=1;i<=n;++i)
		cout<<ans[i]<<' ';
	return 0;
}
