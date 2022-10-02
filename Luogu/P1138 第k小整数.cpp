#include<iostream>
using namespace std;
bool a[30005];
int n,k;
int main()
{
	cin>>n>>k;
	for(int i=0,t;i<n;i++)
	{
		cin>>t;
		a[t]=true;
	}
	for(int i=0,t=0;i<=30003;i++)
	{
		if(a[i])
			t++;
		if(t==k)
		{
			cout<<i<<endl;
			break;
		}
		if(i==30003)
			cout<<"NO RESULT"<<endl;
	}
	return 0;
}
