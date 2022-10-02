#include<iostream>
#include<stack>
using namespace std;
int n,w[250000+2],ans;
stack<int> s;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1,x;i<=n;++i)
		cin>>x>>w[i];
	for(int i=1;i<=n;++i)
	{
		while(not s.empty() and w[s.top()]>w[i])
			s.pop();
		if(s.empty() or w[s.top()]!=w[i])
			++ans;
		s.push(i);
	}
	cout<<ans<<endl;
	return 0;
}
