#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int m,n,m1,n1,ans;
int map[40][40],boot[40][40];
int sx,sy;
void bfs(void)
{
	queue<int> q;
	int px,py,kx,ky,pt;
	int nx[8]={m1,n1,n1,m1,-m1,-n1,-n1,-m1};
	int ny[8]={n1,m1,-m1,-n1,-n1,-m1,m1,n1};
	q.push(sx);	q.push(sy);
	ans=0x7fffffff;
	memset((int*)boot,0x7f,sizeof(boot));
	boot[sx][sy]=0;
	while(not q.empty())
	{
		px=q.front();	q.pop();
		py=q.front();	q.pop();
		pt=boot[px][py];
		for(int i=0;i<8;++i)
		{
			kx=px+nx[i];	ky=py+ny[i];
			if(kx>=1 and ky>=1 and kx<=m and ky<=n and boot[kx][ky]>pt+1)
				if(map[kx][ky]==1)
					boot[kx][ky]=pt+1,q.push(kx),q.push(ky);
				else if(map[kx][ky]==4)
					ans=min(ans,pt+1);
		}
	}
}
int main()
{
	cin>>m>>n>>m1>>n1;
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
		{
			cin>>map[i][j];
			if(map[i][j]==3)
				sx=i,sy=j;
		}
	}
	bfs();
	cout<<ans<<endl;
	return 0;
}
