#include<iostream>
using namespace std;
int main()
{
	int n,num[3],price[3],ans=0x7FFFFFFF;
	cin>>n;
	for(int i=0;i<3;i++)
		cin>>num[i]>>price[i];
	for(int i=0;i<3;i++)
	{
		ans=min(ans,((n%num[i]==0)?(n/num[i]):(n/num[i]+1))*price[i]);
	}
	cout<<ans;
	return 0;
}
