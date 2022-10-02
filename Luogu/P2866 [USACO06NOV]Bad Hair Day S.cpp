#include<iostream>
#include<stack>
using namespace std;
int N,h[80000+2];
long long ans;
stack<int> s;
int main()
{
	ios::sync_with_stdio(false);
	cin>>N;
	for(int i=1;i<=N;++i)
		cin>>h[i];
	for(int i=N;i>=1;--i)
	{
		while(not s.empty() and h[s.top()]<h[i])
			s.pop();
		ans+=(s.empty())?N-i:(s.top()-i-1);
		s.push(i);
	}
	cout<<ans<<endl;
	return 0;
}
