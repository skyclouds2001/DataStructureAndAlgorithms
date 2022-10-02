#include<iostream>
#include<queue>
using namespace std;
int n,m,ans;
char map[103][103];
bool flag[103][103];
queue<int> q;
int nx[4]={0,0,1,-1};
int ny[4]={1,-1,0,0};
int px,py,kx,ky;
void bfs(int x,int y)
{
	q.push(x);	q.push(y);
	flag[x][y]=true;
	while(not q.empty())
	{
		px=q.front();	q.pop();
		py=q.front();	q.pop();
		for(int i=0;i<4;++i)
		{
			kx=px+nx[i];	ky=py+ny[i];
			if(kx>=1 and ky>=1 and kx<=n and ky<=m and map[kx][ky]!='0' and not flag[kx][ky])
				flag[kx][ky]=true,q.push(kx),q.push(ky);
		}
	}
	++ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>map[i][j];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(map[i][j]!='0' and not flag[i][j])
				bfs(i,j);
	cout<<ans<<endl;
	return 0;
}
