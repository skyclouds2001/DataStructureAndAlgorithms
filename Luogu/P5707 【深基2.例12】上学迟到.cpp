#include<iostream>
using namespace std;
int s,v,t,h,m;
int main()
{
	cin>>s>>v;
	t=(s-1)/v+1+10;		//t=s/v+1+10;
	if(t>480)
	{
		t-=480;		//t%=480;
		h=23-(t-1)/60;
		m=59-(t-1)%60;
	}
	else
	{
		h=7-(t-1)/60;
		m=59-(t-1)%60;
	}
	if(h<10&&m<10)
		cout<<'0'<<h<<':'<<'0'<<m<<endl;
	else if(h<10)
		cout<<'0'<<h<<':'<<m<<endl;
	else if(m<10)
		cout<<h<<':'<<'0'<<m<<endl;
	else
		cout<<h<<':'<<m<<endl;
	return 0;
}
