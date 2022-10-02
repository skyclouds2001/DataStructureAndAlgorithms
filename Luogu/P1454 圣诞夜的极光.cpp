#include<iostream>
#include<queue>
using namespace std;
int n,m,ans;
char map[104][104];
bool flag[104][104];
queue<int> q;
int nx[12]={0,0,0,0,1,2,-1,-2,1,1,-1,-1};
int ny[12]={1,2,-1,-2,0,0,0,0,1,-1,1,-1};
void bfs(int x,int y)
{
	while(!q.empty())
		q.pop();
	q.push(x);	q.push(y);
	flag[x][y]=true;
	int px,py,kx,ky;
	while(!q.empty())
	{
		kx=q.front();	q.pop();
		ky=q.front();	q.pop();
		for(int i=0;i<12;++i)
		{
			px=kx+nx[i];	py=ky+ny[i];
			if(px>=1 and py>=1 and px<=n and py<=m)
			{
				if(map[px][py]=='#' and not flag[px][py])
				{
					q.push(px);	q.push(py);
					flag[px][py]=true;
				}
			}
		}
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
			if(map[i][j]=='#' and not flag[i][j])
				bfs(i,j),++ans;
	cout<<ans<<endl;
	return 0;
}
