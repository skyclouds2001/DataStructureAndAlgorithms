#include<iostream>
using namespace std;
bool f[100+4][100+4];
int n,m,k,ans;
int nx[13]={0,0,0,0,1,2,-1,-2,0,1,1,-1,-1};
int ny[13]={1,2,-1,-2,0,0,0,0,0,1,-1,1,-1};
int main()
{
	cin>>n>>m>>k;
	for(int i=1,x,y;i<=m;++i)
	{
		cin>>x>>y;
		for(int k=0;k<13;++k)
		{
			int px=x+nx[k],py=y+ny[k];
			if(px>=1 and px<=n and py>=1 and py<=n)
				f[px][py]=true;
		}
	}
	for(int i=1,o,p;i<=k;++i)
	{
		cin>>o>>p;
		for(int j=-2;j<=2;++j)
			for(int k=-2;k<=2;++k)
				if(o+j>=1 and o+j<=n and p+k>=1 and p+k<=n)
					f[o+j][p+k]=true;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(not f[i][j])
				++ans;
	cout<<ans<<endl;
	return 0;
}
