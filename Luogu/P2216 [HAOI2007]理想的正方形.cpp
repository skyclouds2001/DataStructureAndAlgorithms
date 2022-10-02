#include<iostream>
#include<deque>
using namespace std;
int a,b,n,ans=0x7fffffff;
int num[1005][1005];
int midmax[1005][1005],midmin[1005][1005];
int ansmax[1005][1005],ansmin[1005][1005];
deque<int> dmax,dmin;
int main()
{
	ios::sync_with_stdio(false);
	cin>>a>>b>>n;
	for(int i=1;i<=a;++i)
		for(int j=1;j<=b;++j)
			cin>>num[i][j];
	for(int i=1;i<=a;++i)
	{
		for(int j=1;j<=b;++j)
		{
			if(not dmax.empty() and j-dmax.front()>=n)
				dmax.pop_front();
			while(not dmax.empty() and num[i][dmax.back()]<num[i][j])
				dmax.pop_back();
			dmax.push_back(j);
			if(j>=n)
				midmax[i][j]=num[i][dmax.front()];
			if(not dmin.empty() and j-dmin.front()>=n)
				dmin.pop_front();
			while(not dmin.empty() and num[i][dmin.back()]>num[i][j])
				dmin.pop_back();
			dmin.push_back(j);
			if(j>=n)
				midmin[i][j]=num[i][dmin.front()];
		}
		dmax.clear();
		dmin.clear();
	}
	for(int j=n;j<=b;++j)
	{
		for(int i=1;i<=a;++i)
		{
			if(not dmax.empty() and i-dmax.front()>=n)
				dmax.pop_front();
			while(not dmax.empty() and midmax[dmax.back()][j]<midmax[i][j])
				dmax.pop_back();
			dmax.push_back(i);
			if(i>=n)
				ansmax[i][j]=midmax[dmax.front()][j];
			if(not dmin.empty() and i-dmin.front()>=n)
				dmin.pop_front();
			while(not dmin.empty() and midmin[dmin.back()][j]>midmin[i][j])
				dmin.pop_back();
			dmin.push_back(i);
			if(i>=n)
				ansmin[i][j]=midmin[dmin.front()][j];
		}
		dmax.clear();
		dmin.clear();
	}
	for(int i=n;i<=a;++i)
		for(int j=n;j<=b;++j)
			ans=min(ans,ansmax[i][j]-ansmin[i][j]);
	cout<<ans<<endl;
	return 0;
}
