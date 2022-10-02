#include<cstdio>
#include<cctype>
using namespace std;
int N,ans;
char map[103][203];
bool sym[103][203];
int len[103];
void dfs(int x,int y)
{
	if(sym[x][y] or not islower(map[x][y]))	return;
	sym[x][y]=true;
	dfs(x,y+1);
	dfs(x,y-1);
	dfs(x-1,y);
	dfs(x+1,y);
}
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
	{
		int j=1;
		char t;
		t=getchar();
		while(not islower(t) and t!='*' and t!=' ')	t=getchar();
		while(islower(t) or t==' ' or t=='*')	map[i][j]=t,t=getchar(),++j;
		len[i]=j-1;
	}
	for(int i=1;i<=N;++i)
		for(int j=1;j<=len[i];++j)
			if(islower(map[i][j]) and not sym[i][j])
				dfs(i,j),++ans;
	printf("%d",ans);
	return 0;
}
