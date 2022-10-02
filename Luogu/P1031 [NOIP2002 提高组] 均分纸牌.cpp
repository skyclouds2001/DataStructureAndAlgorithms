#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,a[120],aver,ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i],aver+=a[i];
	aver/=n;
	for(int i=1;i<=n;++i)
	{
		if(a[i]>aver)
			a[i+1]+=(a[i]-aver),a[i]=aver,++ans;
		else if(a[i]<aver)
			a[i+1]-=(aver-a[i]),a[i]=aver,++ans;
	}
	cout<<ans<<endl;
	return 0;
}
