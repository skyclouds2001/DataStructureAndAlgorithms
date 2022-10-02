#include<iostream>
#include<cctype>
#include<queue>
#include<cstring>
using namespace std;
char map[306][306];
int n,m,fly[30][2][2],ans=0x7fffffff,sx,sy,flag[306][306];
queue<int> q;
int nx[4]={0,0,1,-1};
int ny[4]={1,-1,0,0};
void bfs(void)
{
	q.push(sx);	q.push(sy);	q.push(0);
	flag[sx][sy]=0;
	int x,y,t,kx,ky;
	while(!q.empty())
	{
		x=q.front();	q.pop();
		y=q.front();	q.pop();
		t=q.front();	q.pop();
		if(map[x][y]=='=')
		{
			ans=min(ans,t);
			continue;
		}
		for(int i=0;i<4;++i)
		{
			kx=x+nx[i];	ky=y+ny[i];
			if(kx<1 or ky<1 or kx>n or ky>m or map[kx][ky]=='#')
				continue;
			if(isupper(map[kx][ky]))
			{
				int k=map[kx][ky]-'A'+1;
				if(fly[k][1][1]==kx and fly[k][1][2]==ky and fly[k][2][1])
					kx=fly[k][2][1],ky=fly[k][2][2];
				else if(fly[k][2][1]==kx and fly[k][2][2]==ky and fly[k][1][1])
					kx=fly[k][1][1],ky=fly[k][1][2];
				if(flag[kx][ky]>t+1)
				{
					q.push(kx),q.push(ky),q.push(t+1);
					flag[kx][ky]=t+1;
				}
			}
			else if(flag[kx][ky]>t+1)
			{
				q.push(kx);	q.push(ky);	q.push(t+1);
				flag[kx][ky]=t+1;
			}
		}
	}
}
int main()
{
	memset((int*)flag,0x7f,sizeof(flag));
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			cin>>map[i][j];
			if(map[i][j]=='@')
				sx=i,sy=j;
			if(isupper(map[i][j]))
			{
				int k=map[i][j]-'A'+1;
				int d=(fly[k][1][1]==0)?1:2;
				fly[k][d][1]=i;
				fly[k][d][2]=j;
			}
		}
	bfs();
	cout<<ans<<endl;
	return 0;		
}
/*
8 6
###=##
#..W.#
#....#
##@..#
#....#
#....#
#..W.#
######

5
*/
