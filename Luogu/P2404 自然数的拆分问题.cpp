#include<iostream>
using namespace std;
int n,a[10];
void dfs(int res,int n,int k)
{
	if(res==0&&k>1)
	{
		for(int i=0;i<k-1;++i)
			cout<<a[i]<<'+';
		cout<<a[k-1]<<endl;
	}
	else
	{
		for(int i=n;i<=res;++i)
		{
			a[k]=i;
			dfs(res-i,i,k+1);
			a[k]=0;
		}
	}
}
int main()
{
	cin>>n;
	dfs(n,1,0);
	return 0;
}
