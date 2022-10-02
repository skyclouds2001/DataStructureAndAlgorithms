#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
char map[1504][1504];
bool flag[1504][1504];
int num[100004];
int N,M,ans1,ans2;
queue<int> q;
int nx[8]={0,1,1,1,0,-1,-1,-1};
int ny[8]={1,1,0,-1,-1,-1,0,1};
void bfs(int x,int y)
{
	int count=0,px,py,kx,ky;
	q.push(x);	q.push(y);
	flag[x][y]=true;
	++count;
	while(!q.empty())
	{
		px=q.front(),q.pop();
		py=q.front(),q.pop();
		for(int i=0;i<8;++i)
		{
			kx=px+nx[i],ky=py+ny[i];
			if(kx>=1 and ky>=1 and kx<=N and ky<=M \
				and map[kx][ky]=='*' and not flag[kx][ky])
				flag[kx][ky]=true,q.push(kx),q.push(ky),++count;
		}
	}
	++num[count];
}
int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			cin>>map[i][j];
	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			if(map[i][j]=='*' and not flag[i][j])
				bfs(i,j);
	for(int i=1;i<=min(100000,N*M);++i)
		if(num[i])
			++ans1,ans2=max(ans2,num[i]*i);
	cout<<ans1<<' '<<ans2<<endl;
	return 0;
}
