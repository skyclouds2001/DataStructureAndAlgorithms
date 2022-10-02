#include<iostream>
using namespace std;
int nx[4]={0,1,0,-1};
int ny[4]={1,0,-1,0};
bool map[10][10];
bool go[10][10];
int n,m,t,sx,sy,fx,fy,ans;
void search(int x,int y)
{
	if(x==fx&&y==fy)
		++ans;
	else
	{
		for(int i=0;i<4;++i)
		{
			int kx=x+nx[i],ky=y+ny[i];
			if((not go[kx][ky])&&(map[kx][ky]))//下一个可走且没有走过 
			{
				go[kx][ky]=true;
				search(kx,ky);
				go[kx][ky]=false;
			}
		}
	}
}
int main()
{
	cin>>n>>m>>t;
	cin>>sx>>sy>>fx>>fy;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			map[i][j]=true;
	for(int i=1,x,y;i<=t;++i)
		cin>>x>>y,map[x][y]=false;
	go[sx][sy]=true;
	search(sx,sy);
	cout<<ans<<endl;
	return 0;
}
