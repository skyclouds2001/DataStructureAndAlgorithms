#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n,m,ans;
char map[2003][2003];
int boot[2003][2003];
queue<int> q;
int bfs(int x,int y)
{
	q.push(x);	q.push(y);
	boot[x][y]=0;
	int px,py,kx,ky;
	int nx[4]={0,0,1,-1};
	int ny[4]={1,-1,0,0};
	while(not q.empty())
	{
		px=q.front();	q.pop();
		py=q.front();	q.pop();
		if(map[px][py]=='d')
		{
			return boot[px][py];
		}
		for(int i=0;i<4;++i)
		{
			kx=px+nx[i];	ky=py+ny[i];
			if(kx>=1 and ky>=1 and kx<=n and ky<=m \
				and map[kx][ky]!='#' and boot[kx][ky]>boot[px][py]+1)
				q.push(kx),q.push(ky),boot[kx][ky]=boot[px][py]+1;
		}
	}
	return -1;
}
int main()
{
	int sx=0x7fffffff,sy=0x7fffffff;
	ios::sync_with_stdio(false);
	memset(boot,0x7f,sizeof(boot));
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=1 ;j<=m;++j)
			cin>>map[i][j],(map[i][j]=='m')?(sx=i,sy=j):0;
	ans=bfs(sx,sy);
	if(ans==-1)
		cout<<"No Way!"<<endl;
	else
		cout<<ans<<endl;
	return 0;
}
