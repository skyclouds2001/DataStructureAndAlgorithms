#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n,x1,x2,y1,y2,ans;
char map[1005][1005];
int boot[1005][1005];
queue<int> q;
int nx[4]={0,0,1,-1};
int ny[4]={-1,1,0,0};
int bfs(void)
{
	q.push(x1),q.push(y1);
	boot[x1][y1]=0;
	int px,py,kx,ky;
	while(not q.empty())
	{
		px=q.front(),q.pop();
		py=q.front(),q.pop();
		if(px==x2 and py==y2)
			return boot[px][py];
		for(int i=0;i<4;++i)
		{
			kx=px+nx[i],ky=py+ny[i];
			if(kx>=1 and ky>=1 and kx<=n and ky<=n and map[kx][ky]=='0' and boot[kx][ky]>boot[px][py]+1)
				boot[kx][ky]=boot[px][py]+1,q.push(kx),q.push(ky);
		}
	}
}
int main()
{
	//ios::sync_with_stdio(false);
	memset((void*)boot,0x7f,sizeof(boot));
	cin>>n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			cin>>map[i][j];
	cin>>x1>>y1>>x2>>y2;
	ans=bfs();
	cout<<ans<<endl;
	return 0;
}
