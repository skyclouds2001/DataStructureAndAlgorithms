#include<iostream>
using namespace std;
int main()
{
	unsigned long long a,b,num=1,t=0;
	int ans=0;
	cin>>a>>b;
	while(num<b)
		num=(num<<1)+1;
	t=(num+1)>>1;
	while(num>b)
		num=(num-t<a)?num:num-t,t>>=1;
	for(;num;num>>=1)
		if(num&1) ++ans;
	cout<<ans;
	return 0;
}
