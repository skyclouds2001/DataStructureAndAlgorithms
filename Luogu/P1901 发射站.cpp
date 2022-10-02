#include<iostream>
#include<stack>
using namespace std;
int N,H[1000000+2],V[1000000+2],ans[1000000+2],anss;
stack<int> s;
int main()
{
	ios::sync_with_stdio(false);
	cin>>N;
	for(int i=1;i<=N;++i)
		cin>>H[i]>>V[i];
	for(int i=1;i<=N;++i)
	{
		while(not s.empty() and H[s.top()]<H[i])
			s.pop();
		ans[s.empty()?0:s.top()]+=V[i];
		s.push(i);
	}
	while(not s.empty())	s.pop();
	for(int i=N;i>=1;--i)
	{
		while(not s.empty() and H[s.top()]<H[i])
			s.pop();
		ans[s.empty()?0:s.top()]+=V[i];
		s.push(i);
	}
	for(int i=1;i<=N;++i)
		anss=max(anss,ans[i]);
	cout<<anss<<endl;
	return 0;
}
