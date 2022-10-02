#include<iostream>
using namespace std;
int main()
{
	int y;
	bool f;
	cin>>y;
	if(y%400==0||y%4==0&&y%100!=0)	f=1;
	else f=0;
	cout<<f<<endl;
	return 0;
}
