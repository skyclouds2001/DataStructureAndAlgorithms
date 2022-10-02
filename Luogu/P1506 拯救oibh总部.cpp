#include<iostream>
#include<queue>
using namespace std;
int n,m,ans;
char map[506][506];
bool flag[506][506];
int nx[4]={0,0,1,-1};
int ny[4]={1,-1,0,0};
void bfs(void);
int main()
{
	cin>>n>>m;
	for(int i=0;i<=n+1;++i)
		for(int j=0;j<=m+1;++j)
			map[i][j]='0';
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>map[i][j];
	bfs();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(map[i][j]=='0'&&(!flag[i][j]))
				++ans;
	cout<<ans<<endl;
	return 0;
}
void bfs(void)
{
	queue<int> q;
	q.push(0);	q.push(0);
	flag[0][0]=true;
	int x=0,y=0,px=0,py=0;
	while(!q.empty())
	{
		x=q.front();	q.pop();
		y=q.front();	q.pop();
		//cout<<q.size()<<endl;
		//system("pause");
		for(int i=0;i<4;++i)
		{
			px=x+nx[i];	py=y+ny[i];
			if(px>=0&&px<=n+1&&py>=0&&py<=m+1&&map[px][py]=='0'&&(!flag[px][py]))
				flag[px][py]=true,q.push(px),q.push(py);
		}
	}
}
