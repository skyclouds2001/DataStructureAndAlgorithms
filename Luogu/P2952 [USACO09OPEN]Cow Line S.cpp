#include<iostream>
#include<deque>
using namespace std;
deque<int> d;
char c1,c2;
int s,c3;
int main()
{
	cin>>s;
	for(int i=1,f=1;i<=s;++i)
	{
		cin>>c1>>c2;
		if(c1=='A' and c2=='L')
			d.push_front(f),++f;
		if(c1=='A' and c2=='R')
			d.push_back(f),++f;
		if(c1=='D' and c2=='L')
		{
			cin>>c3;
			for(int i=1;i<=c3;++i)
				d.pop_front();
		}
		if(c1=='D' and c2=='R')
		{
			cin>>c3;
			for(int i=1;i<=c3;++i)
				d.pop_back();
		}
	}
	for(int i=0;i<d.size();++i)
		cout<<d.at(i)<<endl;
	return 0;
}
