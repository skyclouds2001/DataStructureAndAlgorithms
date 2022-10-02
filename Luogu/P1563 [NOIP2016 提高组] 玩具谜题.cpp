#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
bool facing[100002];
char work[100002][11];
int a,s,p;
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>facing[i]>>work[i];
	for(int k=0;k<m;k++)
	{
		cin>>a>>s;
		//cout<<"p="<<p<<" a="<<a<<" s="<<s<<" facing[p]="<<facing[p]<<endl;
		if(a==facing[p])
			p=(p+n-s)%n;
		else
			p=(p+s)%n;
	}
	cout<<work[p]<<endl;
	return 0;
} 
