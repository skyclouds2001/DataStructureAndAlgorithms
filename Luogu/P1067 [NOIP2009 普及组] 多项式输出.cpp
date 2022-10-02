#include<iostream>
using namespace std;
short a[105],n;
int main()
{
	cin>>n;
	for(int i=n;i>=0;i--)
		cin>>a[i];
	if(n==0)
	{
		cout<<a[0];
	}
	else if(n==1)
	{
		if(a[1]<0&&a[1]!=-1)
			cout<<a[1]<<'x';
		else if(a[1]>0&&a[1]!=1)
			cout<<a[1]<<'x';
		else if(a[1]==1)
			cout<<'x';
		else if(a[1]==-1)
			cout<<'-'<<'x';
		if(a[0]<0)
			cout<<a[0];
		else if(a[0]>0)
			cout<<'+'<<a[0];
	}
	else
	{
		if(a[n]==1)
			cout<<"x^"<<n;
		else if(a[n]==-1)
			cout<<"-x^"<<n;
		else if(a[n]!=0)
			cout<<a[n]<<"x^"<<n;
		for(int i=n-1;i>=2;i--)
		{
			if(a[i]<0&&a[i]!=-1)
				cout<<a[i]<<"x^"<<i;
			else if(a[i]>0&&a[i]!=1)
				cout<<'+'<<a[i]<<"x^"<<i;
			else if(a[i]==1)
				cout<<'+'<<"x^"<<i;
			else if(a[i]==-1)
				cout<<'-'<<"x^"<<i;
		}
		if(a[1]<0&&a[1]!=-1)
			cout<<a[1]<<'x';
		else if(a[1]>0&&a[1]!=1)
			cout<<'+'<<a[1]<<'x';
		else if(a[1]==1)
			cout<<'+'<<'x';
		else if(a[1]==-1)
			cout<<'-'<<'x';
		if(a[0]<0)
			cout<<a[0];
		else if(a[0]>0)
			cout<<'+'<<a[0];
	}
	return 0;
}
