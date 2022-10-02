#include<iostream>
using namespace std;
int main()
{
	int x;
	cin>>x;
	bool f1=(x%2==0),f2=(x>4&&x<=12);
	bool f[4];
	if(f1&&f2)
		f[0]=true;
	else
		f[0]=false;
	if(f1||f2)
		f[1]=true;
	else
		f[1]=false;
	if((!f1)&&f2||f1&&(!f2))
		f[2]=true;
	else
		f[2]=false;
	if((!f1)&&(!f2))
		f[3]=true;
	else
		f[3]=false;
	for(int i=0;i<4;i++)
		cout<<(int)f[i]<<' ';
	return 0;
}
