#include<iostream>
#include<queue>
using namespace std;
queue<int> qx,qy;
int n;
int map[40][40];
int nx[4]={0,1,0,-1};
int ny[4]={1,0,-1,0};
void bfs(void)
{
	qx.push(0);	qy.push(0);
	map[0][0]=0;
	while(!qx.empty())
	{
		int x=qx.front(),y=qy.front();
		for(int i=0;i<4;++i)
		{
			int kx=x+nx[i],ky=y+ny[i];
			if(kx>=0&&kx<=n+1&&ky>=0&&ky<=n+1&&map[kx][ky]==2)
				map[kx][ky]=0,qx.push(kx),qy.push(ky);
		}	
		qx.pop();	qy.pop();
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<=n+1;++i)
		for(int j=0;j<=n+1;++j)
			map[i][j]=2;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			cin>>map[i][j],(map[i][j]==0)?(map[i][j]=2):1;
	bfs();
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<n;++j)
			cout<<map[i][j]<<' ';
		cout<<map[i][n]<<endl;
	}
	return 0;
}
