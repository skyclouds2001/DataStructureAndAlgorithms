#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	char num[10][5][4]={{{"XXX"},{"X.X"},{"X.X"},{"X.X"},{"XXX"}},
						{{"..X"},{"..X"},{"..X"},{"..X"},{"..X"}},
						{{"XXX"},{"..X"},{"XXX"},{"X.."},{"XXX"}},
						{{"XXX"},{"..X"},{"XXX"},{"..X"},{"XXX"}},
						{{"X.X"},{"X.X"},{"XXX"},{"..X"},{"..X"}},
						{{"XXX"},{"X.."},{"XXX"},{"..X"},{"XXX"}},
						{{"XXX"},{"X.."},{"XXX"},{"X.X"},{"XXX"}},
						{{"XXX"},{"..X"},{"..X"},{"..X"},{"..X"}},
						{{"XXX"},{"X.X"},{"XXX"},{"X.X"},{"XXX"}},
						{{"XXX"},{"X.X"},{"XXX"},{"..X"},{"XXX"}}};
	int n;
	scanf("%d",&n);
	int a[n];
	char t=0,s[n+1];
	scanf("%s",s);
	for(int i=0;i<n;i++)
		a[i]=s[i]-'0';
	for(int k=0;k<5;k++)
	{
		for(int i=0;i<n;i++)
		{
			cout<<num[a[i]][k];
			if(i<n-1)
				cout<<'.';
			else if(i==n-1)
				cout<<endl;
		}
	}
	return 0;
}
/*j
kXXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX
 X.X...X...X...X.X.X.X...X.....X.X.X.X.X
 X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX
 X.X...X.X.....X...X...X.X.X...X.X.X...X
 XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX
*/
