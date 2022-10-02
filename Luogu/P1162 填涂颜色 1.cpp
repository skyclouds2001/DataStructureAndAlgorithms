#include<iostream>
using namespace std;
int map[50][50],n;
int px[8]={0,1,0,-1};
int py[8]={1,0,-1,0};
void search(int x,int y)
{
	if(map[x][y]!=2)	return;
	map[x][y]=0;
	for(int i=0;i<4;++i)
		for(int j=0,kx=x+px[j],ky=y+py[j];j<4;++j,kx=x+px[j],ky=y+py[j])
			if(kx>=0&&kx<=n+1&&ky>=0&&ky<=n+1&&map[kx][ky]==2)
				search(kx,ky);
}
int main()
{
	cin>>n;
	for(int i=0;i<=n+1;++i)
		map[i][0]=2,map[0][i]=2,map[n+1][i]=2,map[i][n+1]=2;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			cin>>map[i][j];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(map[i][j]==0)
				map[i][j]=2;
	search(0,0);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<n;++j)
			cout<<map[i][j]<<' ';
		cout<<map[i][n]<<endl;
	}
	return 0;
}
