#include<bits/stdc++.h>
using namespace std;
map<string,string> m;
string find(string s)
{
	return (s==m[s])?s:(m[s]=find(m[s]));
}
int main()
{
	char s;
	string ss,fa;
	while(true)
	{
		cin>>s;
		if(s=='$')
			break;
		cin>>ss;
		if(s=='?')
			cout<<ss<<' '<<find(ss)<<endl;
		else if(s=='#')
			fa=ss,(m[ss].empty())?(m[ss]=ss):ss;
		else if(s=='+')
			m[ss]=fa;
	}
	return 0;
}
