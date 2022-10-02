#include<iostream>
using namespace std;
int n;
bool f[20];
int num[20];
void dfs(int flow)
{
	if(flow>n)
	{
		for(int i=1;i<=n;++i)
			cout<<"    "<<num[i];
		cout<<endl;
	}
	else
	{
		for(int i=1;i<=n;++i)
		{
			if(not f[i])
			{
				f[i]=true;
				num[flow]=i;
				dfs(flow+1);
				num[flow]=0;
				f[i]=false;
			}
		}
	}
}
int main()
{
	cin>>n;
	dfs(1);
	return 0;
}

