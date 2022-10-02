#include<iostream>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int f(int x)
{
	if(x<10)	return a[x];
	else	return a[x%10]+f(x/10);
}
int main()
{
	int n,count=0;
	cin>>n;
	for(int i=0;i<=1000;i++)
	{
		for(int j=0;j<=1000;j++)
		{
			if(f(i)+f(j)+f(i+j)==n-4)
				count++;
		}
	}
	cout<<count<<endl;
	return 0;
}
