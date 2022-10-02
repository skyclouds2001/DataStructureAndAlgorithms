#include<iostream>
using namespace std;
int f[30];
void ff(void)
{
	f[1]=1;
	f[2]=1;
	for(int i=3;i<25;++i)
		f[i]=f[i-1]+f[i-2];
}
int main()
{
	ff();
	int a,m,n,x,ans;
	cin>>a>>n>>m>>x;
	if(n>=1&&n<=3)
		ans=a;
	else
	{
		if(x==1||x==2)
			ans=a;
		else if(x==3)
			ans=2*a;
		else
		{
			int k=(m-a*(f[n-3]+1))/(f[n-2]-1);
			ans=(f[x-2]+1)*a+(f[x-1]-1)*k;
		}
	}
	cout<<ans;
	return 0;
}
