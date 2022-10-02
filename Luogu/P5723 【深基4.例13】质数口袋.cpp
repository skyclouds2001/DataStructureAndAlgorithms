#include<iostream>
using namespace std;
int isprime(int x)
{
	if(x<0)		return -1;
	else if(x==0||x==1)		return 0;
	else if(x==2||x==5)	return 1;
	else if(x%2==0||x%5==0)		return 0;
	else
	{
		int i=0;
		for(i=3;i<x;i++)
		{
			if(x%i==0)	return 0;
		}
	}
	return 1;
}
int main()
{
	int l,v=0,n=0;
	cin>>l;
	for(int i=2;i<=50000&&v<=l;++i)
		if(isprime(i))
			if(v+i>l)
				break;
			else
				cout<<i<<endl,v+=i,++n;
	cout<<n<<endl;
	return 0;
}
