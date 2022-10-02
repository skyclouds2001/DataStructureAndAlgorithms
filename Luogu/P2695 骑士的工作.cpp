#include<iostream>
#include<algorithm>
using namespace std;
int n,m,head[20003],jack[20003],ans;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>head[i];
	for(int i=1;i<=m;++i)
		cin>>jack[i];
	sort(head+1,head+n+1);
	sort(jack+1,jack+m+1);
	register int i,j;
	for(i=1,j=1;i<=n&&j<=m;)
		if(head[i]<=jack[j])
			ans+=jack[j],++i,++j;
		else
			++j;
	if(i<=n)
		cout<<"you died!";
	else
		cout<<ans;
	return 0;
}
