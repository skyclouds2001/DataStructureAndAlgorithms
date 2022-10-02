#include<iostream>
using namespace std;
int a[7],num,v[7]={0,1,2,3,5,10,20},sum;
bool dp[5000];
int main()
{
	for(int i=1;i<=6;i++)
	{
		cin>>a[i];
		sum+=v[i]*a[i];
	}
	dp[0]=true;
	for(int i=1;i<=6;i++)
	{
		for(int j=sum;j>=0;j--)
		{
			if(dp[j])
			{
				for(int k=1;k<=a[i];k++)
				{
					dp[j+k*v[i]]=true;
				}
			}
		}
	}
	for(int j=1;j<=sum;j++)
		if(dp[j])
			++num;
	cout<<"Total="<<num<<endl;
	return 0;
}
