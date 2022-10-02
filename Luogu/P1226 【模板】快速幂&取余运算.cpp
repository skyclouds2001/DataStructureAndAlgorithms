#include<iostream>
using namespace std;
int main()
{
	long long b,p,k;	//	long long ^_^
	long long s=1;
	cin>>b>>p>>k;
	long long bb=b,pp=p;
	while(pp>0)
	{
		if(pp&1)
			s*=bb,s=(s+k)%k;
		bb*=bb;
		bb=(bb+k)%k;	//	%
		pp>>=1;
	}
	s=(s+k)%k;
	cout<<b<<'^'<<p<<" mod "<<k<<'='<<s<<endl;
	return 0;
}
