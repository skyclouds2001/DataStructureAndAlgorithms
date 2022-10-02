#include<iostream>
#include<algorithm>
using namespace std;
long long n,a[10003],ans,sum;
int main()
{
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n);
	sum=a[0]+a[1];
	ans=sum;
	for(int i=2,j;i<n;++i)
	{
		for(j=i-1;sum>a[j+1]&&j<n-1;++j)
			a[j]=a[j+1];
		a[j]=sum;
		sum=a[i-1]+a[i];
		ans+=sum;
	}
	cout<<ans;
	return 0;
}
