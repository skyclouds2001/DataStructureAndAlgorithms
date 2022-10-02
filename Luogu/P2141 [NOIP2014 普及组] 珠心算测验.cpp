#include<iostream>
using namespace std;
int a[200],n,count;
bool f[20005];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(a[k]==a[i]+a[j]&&(!f[a[k]]))
				{
					count++;
					f[a[k]]=true;
				}
			}
		}
	}
	cout<<count;
	return 0;
}
