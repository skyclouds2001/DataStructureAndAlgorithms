#include<iostream>
using namespace std;
int n,ans,flow[50];
bool chox2[100],chol[50],chox1[100];
void dfs(int x)	//ÐÐºÅ  ÁÐºÅ 
{
	if(x==n)
	{
		if(ans<3)
		{
			for(int i=1;i<n;++i)
				cout<<flow[i]<<' ';
			cout<<flow[n]<<endl;
		}
		++ans;
	}
	else
	{
		for(int i=1;i<=n;++i)
		{
			if((not chol[i]) and (not chox1[x-i+n]) and (not chox2[i+x]))
			{
				flow[x+1]=i;
				chox1[x-i+n]=true;
				chol[i]=true;
				chox2[i+x]=true;
				dfs(x+1);
				chox1[x-i+n]=false;
				chol[i]=false;
				chox2[i+x]=false;
			}
		}
	}
}
int main()
{
	cin>>n;
	dfs(0);
	cout<<ans<<endl;
	return 0;
}
