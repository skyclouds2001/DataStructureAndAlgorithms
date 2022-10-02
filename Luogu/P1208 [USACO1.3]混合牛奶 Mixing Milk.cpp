#include<iostream>
#include<algorithm>
using namespace std;
int m,n,ans;
struct MILK{
	int price,amount;
}milk[5003];
bool cmp(MILK a,MILK b)
{
	return (a.price<b.price);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i)
		cin>>milk[i].price>>milk[i].amount;
	sort(milk+1,milk+m+1,cmp);
	for(int i=1,t=n;t>0;++i)
	{
		if(t>=milk[i].amount)
			t-=milk[i].amount,ans+=milk[i].price*milk[i].amount;
		else
			ans+=milk[i].price*t,t=0;
	}
	cout<<ans;
	return 0;
} 
