#include<iostream>
#include<stack>
using namespace std;
int N,H[100000+2],ans[100000+2];
stack<int> s;
int main()
{
	ios::sync_with_stdio(false);
	cin>>N;
	for(int i=1;i<=N;++i)
		cin>>H[i];
	for(int i=N;i>=1;--i)
	{
		while(not s.empty() and H[s.top()]<=H[i])
			s.pop();
		ans[i]=s.empty()?0:s.top();
		s.push(i);
	}
	for(int i=1;i<=N;++i)
		cout<<ans[i]<<endl;
	return 0;
}
