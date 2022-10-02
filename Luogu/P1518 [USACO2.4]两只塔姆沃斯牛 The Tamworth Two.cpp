#include<iostream>
using namespace std;
char map[10][10];
int fx,fy,fk,cx,cy,ck,t;
int movex[4]={-1,0,1,0};
int movey[4]={0,1,0,-1};
int main()
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			cin>>map[i][j];
			if(map[i][j]=='F')
			{
				fx=i;	fy=j;
			}
			if(map[i][j]=='C')
			{
				cx=i;	cy=j;
			}
		}
	}
	int tx,ty,flag;
	flag=fx+fy*10+cx*100+cy*1000+fk*10000+ck*40000;
	while(1)
	{
		tx=fx+movex[fk],ty=fy+movey[fk];
		if(tx<0||tx>9||ty<0||ty>9||map[tx][ty]=='*')
			fk=(fk+1)%4;
		else
		{
			fx=tx;	fy=ty;
		}
		tx=cx+movex[ck],ty=cy+movey[ck];
		if(tx<0||tx>9||ty<0||ty>9||map[tx][ty]=='*')
			ck=(ck+1)%4;
		else
		{
			cx=tx;	cy=ty;
		}
		t++;
		if(flag==fx+fy*10+cx*100+cy*1000+fk*10000+ck*40000||t>10000)
		{
			cout<<0<<endl;	break;
		}
		if(cx==fx&&cy==fy)
		{
			cout<<t<<endl;	break;
		}	
	}
	return 0;
}
