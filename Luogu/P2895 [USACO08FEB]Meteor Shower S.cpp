#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int m,map[400][400];	//记录流星落下时间，无穷大表示不会落下 
int ans,flag[400][400];	//记录到当前的最短时间 
queue<int>	q;
int nx[4]={0,0,1,-1};
int ny[4]={1,-1,0,0};
void bfs(void)
{
	int x,y,t;
	flag[0][0]=0;
	q.push(0);	q.push(0);
	while(!q.empty())
	{
		x=q.front();	q.pop();
		y=q.front();	q.pop();
		t=flag[x][y];
		if(map[x][y]>1000)
		{
			ans=min(ans,t);
			continue;
		}	
		for(int i=0,px,py;i<4;++i)
		{
			px=x+nx[i];	py=y+ny[i];
			if(px>=0&&py>=0&&map[px][py]>t+1&&flag[px][py]>t+1)
				flag[px][py]=t+1,q.push(px),q.push(py);
		}
	}
}
int main()
{
	memset((int*)map,0x7f,sizeof(map));	//2139062143
	memset((int*)flag,0x7f,sizeof(flag));
	ans=0x7fffffff;		//2147483647
	cin>>m;
	for(int i=1,x,y,t;i<=m;++i)
	{
		cin>>x>>y>>t;
		map[x][y]=min(map[x][y],t);
		for(int j=0,px,py;j<4;++j)
		{
			px=x+nx[j];	py=y+ny[j];
			if(px>=0&&py>=0)
				map[px][py]=min(map[px][py],t);
		}
	}
	bfs();
	if(ans==0x7fffffff)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;	
	return 0;
}
