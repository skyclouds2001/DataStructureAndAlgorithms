#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string a,b,sum;
int t,n1,n2,n,k;
int main()
{
	cin>>a;
	cin>>b;
	n1=a.length();
	n2=b.length();
	if(n1>n2)
	{
		t=n1-n2;
		while(t-->0)
			b="0"+b;
	}
	else if(n1<n2)
	{
		t=n2-n1;
		while(t-->0)
			a="0"+a;
	}
	int len=a.length();
	for(int i=len-1;i>=0;i--)
	{
		t=(a[i]-'0')+(b[i]-'0')+k;
		k=t/10;
		t%=10;
		sum=(char)(t+'0')+sum;
	}
	if(k>0)	sum="1"+sum;
	cout<<sum<<endl;
	return 0;
}
