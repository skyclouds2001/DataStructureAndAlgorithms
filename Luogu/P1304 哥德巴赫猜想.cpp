#include<iostream>
#include<cmath>
using namespace std;
bool prime[10005];
bool isprime(int x)
{
	if(x%2==0||x%5==0)	return false;
	else
	{
		for(int i=3;i<=sqrt(x);i+=2)
		{
			if(x%i==0)	return false;
		}
	}
	return true;
}
void loadprime(void)
{
	prime[2]=true;
	prime[3]=true;
	prime[5]=true;
	prime[7]=true;
	for(int i=11;i<=9999;i+=2)
	{
		if(isprime(i))
			prime[i]=true;
	}
}
int main()
{
	loadprime();
	int N;
	cin>>N;
	cout<<"4=2+2"<<endl;
	for(int i=6;i<=N;i+=2)
	{
		for(int j=3;j<=N-3;j+=2)
		{
			if(prime[j]&&prime[i-j])
			{
				cout<<i<<'='<<j<<'+'<<i-j<<endl;
				break;
			}
		}
	}
	return 0;
} 
