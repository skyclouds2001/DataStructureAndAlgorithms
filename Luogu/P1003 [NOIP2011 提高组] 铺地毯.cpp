#include<iostream>
using namespace std;
int a[10005],b[10005],g[10005],k[10005],n,x,y;
int main()
{
	bool f=false;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i]>>g[i]>>k[i];
	cin>>x>>y;
	for(int i=n;i>0;i--)
	{
		if(x>=a[i]&&y>=b[i]&&x<=a[i]+g[i]&&y<=b[i]+k[i])
		{
			cout<<i<<endl;
			f=true;
			break;
		}
	}
	if(!f)	cout<<-1<<endl;
	return 0;
}
