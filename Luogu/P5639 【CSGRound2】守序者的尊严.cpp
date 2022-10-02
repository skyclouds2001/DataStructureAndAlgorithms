#include<iostream>
#include<cstdio>
using namespace std;
int n,ans;
bool a[1000003];
int main()
{
	cin>>n;
	for(int i=1,t;i<=n;++i)
		scanf("%d",&t),a[i]=t;
	bool flag=false;
	for(int i=1;i<=n;)
	{
		if(flag)
			while(a[i]&&i<=n)	++i;
		else
			while(!a[i]&&i<=n)	++i;
		flag=!flag;
		++ans;
	}
	cout<<ans;
	return 0;
}
