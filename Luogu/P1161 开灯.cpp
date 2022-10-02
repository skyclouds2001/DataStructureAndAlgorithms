#include<iostream>
using namespace std;
bool light[2000005];
int n,t;
double a;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>t;
		for(int j=1;j<=t;j++)
			light[(int)(j*a)]=!light[(int)(j*a)];
	}
	for(int j=1;1;j++)
	{
		if(light[j])
		{
			cout<<j;
			break;
		}
	}
	return 0;
}
