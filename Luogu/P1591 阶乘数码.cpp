#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int b[3000],n,a,t,ans,p;
int main()
{
	cin>>t;
	for(int k=0;k<t;++k)
	{
		memset(b,0,sizeof(b));
		cin>>n>>a;
		b[0]=1;
		ans=0;
		p=0;
		for(int i=2,t=0,j=0;i<=n;++i)
		{
			for(t=0,j=0;j<=p;++j)
			{
				b[j]=b[j]*i+t;
				t=b[j]/10;
				b[j]%=10;
			}
			while(t!=0)
			{
				b[j]=t%10;
				t/=10;
				++j;
			}
			p=j-1;
		}
		for(int i=0;i<=p;++i)
			if(b[i]==a)	++ans;
		cout<<ans<<endl;
	}
	return 0;
}
