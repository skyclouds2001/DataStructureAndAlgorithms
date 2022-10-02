#include<iostream>
#include<cmath>
using namespace std;
int n,s[20],b[20],ans=0x7fffffff;
void dfs(int f,int fs,int fb)
{
	if(f==n&&fs!=1&&fb!=0)
	{
		ans=min(ans,(int)fabs(fs-fb));
		return;
	}
	if(f>=n)	return;
	dfs(f+1,fs*s[f+1],fb+b[f+1]);
	dfs(f+1,fs,fb);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>s[i]>>b[i];
	dfs(0,1,0);
	cout<<ans<<endl;
	return 0;
}
