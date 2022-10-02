#include<iostream>
#include<queue>
using namespace std;
int H,W,sx,sy,ans;
char map[24][24];
bool flag[24][24];
int nx[4]={0,0,1,-1};
int ny[4]={1,-1,0,0};
void dfs(int x,int y)
{
	if(map[x][y]=='.')	++ans;
	for(int i=0,px,py;i<4;++i)
	{
		px=x+nx[i];	py=y+ny[i];
		if(px>=1 and py>=1 and px<=H and py<=W and map[px][py]!='#' and not flag[px][py])
		{
			flag[px][py]=true;
			dfs(px,py);
		}
	}
}
int main()
{
	cin>>W>>H;
	for(int i=1;i<=H;++i)
		for(int j=1;j<=W;++j)
			cin>>map[i][j],(map[i][j]=='@')?(sx=i,sy=j):1;
	flag[sx][sy]=true;
	++ans;
	dfs(sx,sy);
	cout<<ans<<endl;
	return 0;
}
