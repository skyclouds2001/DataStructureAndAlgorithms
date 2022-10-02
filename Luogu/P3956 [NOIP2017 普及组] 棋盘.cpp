#include<cstdio>
short pcolor[101][101];
int pmoney[101][101];
int m,n;
short px[4]={0,1,0,-1};					/*magic: unusable:0 usable:1 */
short py[4]={1,0,-1,0};					/*color: RED:1 YELLOW:2 */
void f(short x,short y,short color,bool magic,int cost)
{
	if(pmoney[x][y]<=cost&&(x!=1||y!=1))	return;
	pmoney[x][y]=cost;
	int nx=0,ny=0;
	for(int i=0;i<4;i++)
	{
		nx=x+px[i];	ny=y+py[i];
		if(nx<1||ny<1||nx>m||ny>m)	continue;
		if(color==pcolor[nx][ny])
			f(nx,ny,color,1,cost);
		else
		{
			if(pcolor[nx][ny]!=0)
				f(nx,ny,pcolor[nx][ny],1,cost+1);
			else
			{
				if(magic)
				{
					f(nx,ny,color,0,cost+2);
				}
			}
		}
	}
}
int main()
{
	int i=0,j=0,t=0;
	scanf("%d%d",&m,&n);
	for(int k=0;k<n;k++)
	{
		scanf("%d%d%d",&i,&j,&t);
		pcolor[i][j]=t+1;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			pmoney[i][j]=0x7FFFFFFF;
		}
	}
	pmoney[1][1]=0;
	f(1,1,pcolor[1][1],1,0);
	if(pmoney[m][m]==0x7FFFFFFF)	printf("-1");
	else	printf("%hd",pmoney[m][m]);
	return 0;
 } 
