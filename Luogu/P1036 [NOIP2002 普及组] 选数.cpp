#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,k,x[30],count;
bool isprime(int x)
{
	if(x<0)		return false;
	else if(x==0||x==1)		return false;
	else if(x==2||x==5)	return true;
	else if(x%2==0||x%5==0)		return false;
	else
	{
		int i;
		for(i=3;i<=sqrt(x);i+=2)
		{
			if(x%i==0)	return false;
		}
	}
	return true;
}
void dfs(int k,int p,long long sum)
{
	if(k==0)
	{
		if(isprime(sum))
			count++;
	}
	else
	{
		for(int i=p+1;i<=n;i++)
		{
			dfs(k-1,i,sum+x[i]);
		}
	}
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	dfs(k,0,0);
	cout<<count<<endl;
	return 0;
} 
