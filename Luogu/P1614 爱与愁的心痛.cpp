#include<iostream>
using namespace std;
short n,m,a[3005];
int sum,smin;
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int k=0;k<m;k++)
		sum+=a[k];
	smin=sum;
	for(int i=1;i<=n-m;i++)
	{
		sum-=a[i-1];
		sum+=a[i+m-1];
		smin=min(sum,smin);
	}
	cout<<smin<<endl;
	return 0;
}
