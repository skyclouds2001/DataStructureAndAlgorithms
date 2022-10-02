#include<iostream>
#include<cstdio>
using namespace std;
int n,r;
int num[50];
bool flag[50];
void dfs(int flow)
{
	if(flow>r)
	{
		for(int i=1;i<=r;++i)
			printf("%3d",num[i]);
		cout<<endl;
	}
	else
	{
		for(int i=1;i<=n;++i)
		{
			if(not flag[i] and num[flow-1]<i)
			{
				flag[i]=true;
				num[flow]=i;
				dfs(flow+1);
				num[flow]=0;
				flag[i]=false;
			}
		}
	}
}
int main()
{
	cin>>n>>r;
	dfs(1);
	return 0;
}
