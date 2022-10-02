#include<iostream>
using namespace std;
int GCD(int a,int b)
{
	if(b==0)	return a;
	return		GCD(b,a%b);
}
void swap(int *a,int *b)
{
	int t;
	t=*a;	*a=*b;	*b=t;
}
int main()
{
	int a[3];
	cin>>a[0]>>a[1]>>a[2];
	if(a[0]>a[1])	swap(a,a+1);
	if(a[1]>a[2])	swap(a+1,a+2);
	if(a[0]>a[2])	swap(a,a+2);
	int t=GCD(a[2],a[0]);
	cout<<a[0]/t<<'/'<<a[2]/t<<endl;
	return 0;
}
