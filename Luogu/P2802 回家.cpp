#include<iostream>
using namespace std;
int n,m,ans=0x0fffffff,sx,sy,ex,ey;
int map[12][12];
int nx[4]={0,0,1,-1};
int ny[4]={1,-1,0,0};
void dfs(int x,int y,int blood,int time)
{								//当前位置x，y 血量为b 时间为t 
	if(blood==0||time>m*n||time>ans)	return;
	if(map[x][y]==4)	blood=6;
	if(x==ex&&y==ey||map[x][y]==3)
		ans=min(ans,time);
	else
	{
		int kx,ky;
		for(int i=0;i<4;++i)
		{
			kx=x+nx[i];	ky=y+ny[i];
			if(kx>=1&&kx<=n&&ky>=1&&ky<=m&&map[kx][ky]!=0)
				dfs(kx,ky,blood-1,time+1);
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			cin>>map[i][j];
			if(map[i][j]==2)
				sx=i,sy=j;
			if(map[i][j]==3)
				ex=i,ey=j;
		}
	dfs(sx,sy,6,0);
	if(ans==0x0fffffff)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
	return 0;
}
