#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n,m;
char map[200][200];
int dis[200][200];
queue<int> q;
int nx[4]={0,0,1,-1};
int ny[4]={1,-1,0,0};
void bfs(int x,int y)
{
	q.push(x);	q.push(y);
	dis[x][y]=0;
	int px,py,pt,kx,ky;
	while(not q.empty())
	{
		px=q.front();	q.pop();
		py=q.front();	q.pop();
		pt=dis[px][py];
		for(int i=0;i<4;++i)
		{
			kx=px+nx[i];	ky=py+ny[i];
			if(kx>=1 and ky>=1 and kx<=n and ky<=m and \
				map[kx][ky]=='0' and dis[kx][ky]>pt+1)
				q.push(kx),q.push(ky),dis[kx][ky]=pt+1;
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>map[i][j];
	memset((void*)dis,0x7f,sizeof(dis));
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(map[i][j]=='1')
				bfs(i,j);
		}
	}
	for(int i=1;i<=n;++i,cout<<endl)
		for(int j=1;j<=m;++j)
			cout<<dis[i][j]<<' ';
	return 0;
}
