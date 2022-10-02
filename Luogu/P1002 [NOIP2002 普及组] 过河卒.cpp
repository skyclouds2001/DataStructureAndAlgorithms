#include<iostream>
using namespace std;
long long p[30][30];
bool f[30][30];
int n,m;
int kx[9]={0,-1,-2,-2,-1,1,2,2,1},mx;
int ky[9]={0,-2,-1,1,2,2,1,-1,-2},my;
int main()
{
	cin>>n>>m>>mx>>my;
	for(int i=0;i<9;i++)
	{
		if(mx+kx[i]>=0&&mx+kx[i]<=n&&my+ky[i]>=0&&my+ky[i]<=m)
			f[mx+kx[i]][my+ky[i]]=true;
	}
	for(int j=0;j<=m&&!f[0][j];j++)
		p[0][j]=1;
	for(int i=0;i<=n&&!f[i][0];i++)
		p[i][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!f[i][j])
			{
				if(i>0)
					p[i][j]+=p[i-1][j];
				if(j>0)
					p[i][j]+=p[i][j-1];
			}
			else
				p[i][j]=0;
		}
	}
	cout<<p[n][m]<<endl;
	return 0;
}
