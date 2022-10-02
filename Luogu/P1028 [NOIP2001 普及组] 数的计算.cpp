#include<iostream>
#include<cstdio>
using namespace std;
int F[1003];
int main()
{
	int n;
	cin>>n;
	F[0]=1;	F[1]=1;	F[2]=2;	F[3]=2;
	for(int i=4;i<=1000;i++)
		F[i]=F[i-2]+F[i/2];
	cout<<F[n]<<endl;
	return 0;
}
