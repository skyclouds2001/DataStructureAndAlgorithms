#include<iostream>
using namespace std;
bool f[3001];
bool isicy(int x)
{
	if(x%400==0||x%4==0&&x%100!=0)	return true;
	else	return false;
}
void loadicy(void)
{
	for(int i=1582;i<=3000;i+=2)
	{
		f[i]=isicy(i);
	}
}
int main()
{
	loadicy();
	int x,y,count=0;
	cin>>x>>y;
	for(int i=x;i<=y;i++)
	{
		if(f[i])	count++;
	}
	cout<<count<<endl;
	for(int i=x;i<=y;i++)
	{
		if(f[i])	cout<<i<<' ';
	}
	return 0;
}
