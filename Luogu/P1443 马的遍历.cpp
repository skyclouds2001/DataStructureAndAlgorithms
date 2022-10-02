#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
queue<int> q;
int n,m,ans[404][404],x,y;
int nx[8]={1,2,2,1,-1,-2,-2,-1};
int ny[8]={2,1,-1,-2,-2,-1,1,2};
int main()
{
	memset((int*)ans,0x7f,sizeof(ans));
	cin>>n>>m>>x>>y;
	q.push(x);	q.push(y);
	ans[x][y]=0;
	int px,py,kx,ky,boot;
	while(not q.empty())
	{
		px=q.front();	q.pop();
		py=q.front();	q.pop();
		boot=ans[px][py];
		for(int i=0;i<8;++i)
		{
			kx=px+nx[i];	ky=py+ny[i];
			if(kx>0 and ky>0 and kx<=n and ky<=m and ans[kx][ky]>boot+1)
				ans[kx][ky]=boot+1,q.push(kx),q.push(ky);
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			if(ans[i][j]==0x7f7f7f7f)
				printf("-1   ");
			else
				printf("%-5d",ans[i][j]);
		cout<<endl;
	}
	return 0;
}
