#include<iostream>
using namespace std;
int a[5000000+4],n,p,ans=0x7fffffff,sum;
int main()
{
	cin>>n>>p;
	for(int i=1,t,pre=0;i<=n;++i)
		cin>>t,a[i]=t-pre,pre=t;
	for(int i=1,x,y,z;i<=p;++i)
		cin>>x>>y>>z,a[x]+=z,a[y+1]-=z;
	for(int i=1;i<=n;++i)
		sum+=a[i],ans=min(ans,sum);
	cout<<ans<<endl;
	return 0;
}
