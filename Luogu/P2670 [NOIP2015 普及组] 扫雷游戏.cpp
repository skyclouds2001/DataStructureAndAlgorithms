#include<iostream>
#include<cstdio>
using namespace std;
int px[8]={0,1,1,1,0,-1,-1,-1};
int py[8]={1,1,0,-1,-1,-1,0,1};
char s[101][101];
int main()
{
	int n,m,count;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>s[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='?')
			{
				count=0;
				for(int k=0;k<8;k++)
				{
					if(s[i+px[k]][j+py[k]]=='*')	count++;
				}
				s[i][j]=count+'0';
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<s[i][j];
		}
		cout<<endl;
	}
	return 0;
}
