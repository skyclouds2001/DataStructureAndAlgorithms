#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
queue<int> q;
int n,m,a,b;
int flag[500+4][500+4];
int nx[4]={0,0,1,-1};
int ny[4]={1,-1,0,0};
void bfs(void)
{
	int px,py,kx,ky,t;
	while(not q.empty())
	{
		px=q.front(),q.pop();
		py=q.front(),q.pop();
		t=flag[px][py];
		for(int i=0;i<4;++i)
		{
			kx=px+nx[i];	ky=py+ny[i];
			if(kx>=1 and ky>=1 and kx<=n and ky<=m and flag[kx][ky]>t+1)
				flag[kx][ky]=t+1,q.push(kx),q.push(ky);
		}
	}
}
int main()
{
	memset((void*)flag,0x7f,sizeof(flag));
	cin>>n>>m>>a>>b;
	for(int i=1,x,y;i<=a;++i)
		scanf("%d%d",&x,&y),q.push(x),q.push(y),flag[x][y]=0;
	bfs();
	for(int i=1,x,y;i<=b;++i)
		scanf("%d%d",&x,&y),printf("%d\n",flag[x][y]);
	return 0;
}
