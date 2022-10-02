#include<iostream>
using namespace std;
int n,m,ans;
char map[101][101];
bool flag[101][101];
int px[8]={0,1,1,1,0,-1,-1,-1};
int py[8]={1,1,0,-1,-1,-1,0,1};
void check(int x,int y)
{
	if(x<1||y<1||x>n||y>m)
		return;
	for(int i=0;i<8;++i)
	{
		int kx=x+px[i],ky=y+py[i];
		if(map[kx][ky]=='W'&&(!flag[kx][ky]))
			flag[kx][ky]=true,check(kx,ky);
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>map[i][j];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(map[i][j]=='W'&&(!flag[i][j]))
				++ans,flag[i][j]=true,check(i,j);
	cout<<ans<<endl;
	return 0;
}
