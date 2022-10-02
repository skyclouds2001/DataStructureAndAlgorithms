#include<iostream>
#include<algorithm>
using namespace std;
struct FOOD{
	long long a,b,c;
}s[100];
bool cmp(FOOD m,FOOD n)
{
	return (m.c*n.b<n.c*m.b);
}
int T,n;
long long dp[100005],ans;
int main()
{
	cin>>T>>n;
	for(int i=1;i<=n;++i)
		cin>>s[i].a;
	for(int i=1;i<=n;++i)
		cin>>s[i].b;
	for(int i=1;i<=n;++i)
		cin>>s[i].c;
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=n;++i)
		for(int j=T;j>=s[i].c;--j)
			dp[j]=max(dp[j],dp[j-s[i].c]+s[i].a-j*s[i].b);
	for(int j=0;j<=T;++j)
		ans=max(ans,dp[j]);
	cout<<ans<<endl;
	return 0;
}
