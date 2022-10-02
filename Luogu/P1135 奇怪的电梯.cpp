#include<iostream>
#include<cstring>
using namespace std;
int N,A,B,K[204],ans=0x7fffffff,flag[204];
void dfs(int floor,int press)		//now position |now press
{
	if(floor==B)
		ans=min(ans,press);
	else
	{
		if(floor-K[floor]>0 and press+1<flag[floor-K[floor]])
			flag[floor-K[floor]]=press+1,dfs(floor-K[floor],press+1);
		if(floor+K[floor]<=N and press+1<flag[floor+K[floor]])
			flag[floor+K[floor]]=press+1,dfs(floor+K[floor],press+1);
	}
}
int main()
{
	memset(flag,0x7f,sizeof(flag));
	cin>>N>>A>>B;
	for(int i=1;i<=N;++i)
		cin>>K[i];
	flag[A]=0;
	dfs(A,0);
	if(ans==0x7fffffff)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
	return 0;
}
