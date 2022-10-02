#include<iostream>
using namespace std;
int N,K,fa[50000*3+4],f,x,y,ans;
int find(int x)
{
	return (x==fa[x])?x:(fa[x]=find(fa[x]));
}
void merge(int x,int y)
{
	fa[find(x)]=find(y);
}
int main()
{
	cin>>N>>K;
	for(int k=1;k<=N*3;++k)	 	//i吃i+n,被i+2n吃,i+2n吃i 
		fa[k]=k;	//用i+n表示i的捕食对象,而i+2n表示i的天敌 
	for(int k=1;k<=K;++k)
	{
		cin>>f>>x>>y;
		if(x>N or y>N)
		{					//特判x或y不在食物链中的情况 
			++ans;
			continue;
		}
		if(f==1)
		{
			if(find(x)==find(y+N) or find(x)==find(y+N*2)\
			/*or find(y)==find(x+N) or find(y)==find(x+2*N)*/ )
			{			//如果已知x吃y,或者x被y吃,说明这是假话 
				++ans;	//无需：已知y吃x,或者y被x吃 
				continue;
			}
			merge(x,y);				//这是真话,则x和y是一族 
			merge(x+N,y+N);			//x的猎物和y的猎物是一族 
			merge(x+2*N,y+2*N);		//x的天敌和y的天敌是一族 
		}
		else if(f==2)
		{
			if(find(x)==find(y) or find(x)==find(y+N*2)\
				/*or find(y)==find(x+N)*/ )
			{	//如果已知x与y是一族,或者x被y吃,说明这是假话 
				++ans;		//无需：已知x吃y 
				continue;
			}
			merge(x,y+N);		//这是真话,则x吃y 
			merge(y,x+2*N);		//x的猎物吃y的猎物 
			merge(x+N,y+2*N);//x的天敌吃y的天敌,或者说y吃x的天敌 
		}
	}
	cout<<ans<<endl;
	return 0;
}
