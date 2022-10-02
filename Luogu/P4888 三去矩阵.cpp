#include<iostream>
using namespace std;
int l,q;
char map[2003][2003];
int main()
{
	ios::sync_with_stdio(false);
	cin>>l>>q;
	for(int i=1;i<=l;++i)
		for(int j=1;j<=l;++j)
			cin>>map[i][j];
	for(int k=1;k<=q;++k)
	{
		int x,y,pi=0,pj=0,ans=0;
		cin>>x>>y;
		for(;x-pi>=1 and x+pi<=l and map[x+pi][y]==map[x-pi][y];++pi) ;
		for(;y-pj>=1 and y+pj<=l and map[x][y+pj]==map[x][y-pj];++pj) ;
		ans=max(1+(pi-1)*2,1+(pj-1)*2);
		cout<<ans<<endl;
	}
	return 0;
}
