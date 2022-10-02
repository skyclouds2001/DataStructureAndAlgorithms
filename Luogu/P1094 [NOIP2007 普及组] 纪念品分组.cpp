#include<iostream>
#include<algorithm>
using namespace std;
int w,n,p[30004],ans;
int main()
{
	cin>>w>>n;
	for(int i=1;i<=n;++i)
		cin>>p[i];
	sort(p+1,p+n+1);
	for(int i=1,j=n;i<=j;)
		if(p[j]+p[i]>w)
			++ans,--j;
		else
			++ans,++i,--j;
	cout<<ans;
	return 0;
}
