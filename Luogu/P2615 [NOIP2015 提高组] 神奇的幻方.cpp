#include<iostream>
using namespace std;
int map[40][40],n;
int main()
{
	int px,py;
	cin>>n;
	map[1][n/2+1]=1;
	px=1;	py=n/2+1;
	for(int i=2;i<=n*n;i++)
	{
		if(px==1&&py!=n)
		{
			px=n;	py++;
		}
		else if(py==n&&px!=1)
		{
			px--;	py=1;
		}
		else if(px==1&&py==n)
		{
			px++;
		}
		else
		{
			if(map[px-1][py+1]==0)
			{
				px--;	py++;
			}
			else	px++;
		}
		map[px][py]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<map[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
