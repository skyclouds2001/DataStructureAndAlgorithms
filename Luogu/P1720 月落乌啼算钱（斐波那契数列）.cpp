#include<iostream>
using namespace std;
unsigned long long a[50],n;
int main()
{	
	cin>>n;
	if(n==0)
	{
		cout<<"0.00"<<endl;
		return 0;
	}
	a[1]=1;	a[2]=1;
	for(int i=3;i<=n;i++)
		a[i]=a[i-1]+a[i-2];
	cout<<a[n]<<".00"<<endl;
	return 0;
}
