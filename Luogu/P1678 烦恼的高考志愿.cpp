#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int m,n,a[100003],b[100003];
long long sum;
int l,r,mid;
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	sort(a+1,a+m+1);
	for(int k=1;k<=n;k++)
	{
		if(a[1]>=b[k])
		{
			sum+=(a[1]-b[k]);
			goto OUT;
		}
		if(a[m]<=b[k])
		{
			sum+=(b[k]-a[m]);
			goto OUT;
		}
		l=0;	r=m+1;	//l=1;	r=m;
		while(l<r)	 //l<r
		{
			mid=(l+r)/2;
			/*if(a[mid]==b[k])
				goto OUT;
			else if(a[mid]>b[k])
				r=mid-1;
			else
				l=mid+1;*/
			if(a[mid]<=b[k])
				l=mid+1;
			else
				r=mid;
		}
		sum+=min(abs(a[l]-b[k]),abs(a[l-1]-b[k]));
		OUT:;
	}
	cout<<sum;
	return 0;
}
