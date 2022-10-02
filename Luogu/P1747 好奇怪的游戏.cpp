#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int sx1,sx2,sy1,sy2;
int ans;
int nx[12]={1,2,2,2,2,1,-1,-2,-2,-2,-2,-1};
int ny[12]={2,2,1,-1,-2,-2,-2,-2,-1,1,2,2};
int px,py,kx,ky,pt;
int flag[28][28];
queue<int> q;
void bfs(int x,int y)
{
	memset((int*)flag,0x7f,sizeof(flag));
	ans=0x7fffffff;
	q.push(x);	q.push(y);
	flag[x][y]=0;
	while(not q.empty())
	{
		px=q.front();	q.pop();
		py=q.front();	q.pop();
		pt=flag[px][py];
		if(px==1 and py==1)
			ans=min(ans,pt);
		for(int i=0;i<12;++i)
		{
			kx=px+nx[i];	ky=py+ny[i];
			if(kx>=1 and ky>=1 and kx<=20 and ky<=20 \
			and flag[kx][ky]>pt+1)
				flag[kx][ky]=pt+1,q.push(kx),q.push(ky);
		}
	}
}
int main()
{
	cin>>sx1>>sy1>>sx2>>sy2;
	bfs(sx1,sy1);
	cout<<ans<<endl;
	bfs(sx2,sy2);
	cout<<ans<<endl;
	return 0;
}
