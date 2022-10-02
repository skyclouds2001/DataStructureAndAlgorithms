#include<iostream>
using namespace std;
int a[10];
void f(int x)
{
	while(x)
	{
		++a[x%10];
		x/=10;
	}
}
int main()
{
	int m,n;
	cin>>m>>n;
	for(int i=min(m,n);i<=max(m,n);++i)
		f(i);
	for(int i=0;i<10;++i)
		cout<<a[i]<<' ';
	return 0;
}
