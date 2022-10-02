#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=1,num=1;i<=n;++i)
	{
		for(int j=1;j<=n-i+1;++j,++num)
			if(num<10)
				cout<<'0'<<num;
			else
				cout<<num;
		cout<<endl;
	}
	return 0;
}
