#include<bits/stdc++.h>
using namespace std;
int n,q;
int stmax[50000+3][20],stmin[50000+3][20];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1,t;i<=n;++i)
		cin>>t,stmax[i][0]=t,stmin[i][0]=t;
	for(int j=1;j<=19;++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
		{
			stmax[i][j]=max(stmax[i][j-1],stmax[i+(1<<(j-1))][j-1]);
			stmin[i][j]=min(stmin[i][j-1],stmin[i+(1<<(j-1))][j-1]);
		}
	for(int k=1,l,r,s;k<=q;++k)
	{
		cin>>l>>r;
		s=__lg(r-l+1);
		cout<<max(stmax[l][s],stmax[r-(1<<s)+1][s])-\
			min(stmin[l][s],stmin[r-(1<<s)+1][s])<<endl;
	}
	return 0;
}
