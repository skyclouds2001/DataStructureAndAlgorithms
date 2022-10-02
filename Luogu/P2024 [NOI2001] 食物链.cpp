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
	for(int k=1;k<=N*3;++k)	 	//i��i+n,��i+2n��,i+2n��i 
		fa[k]=k;	//��i+n��ʾi�Ĳ�ʳ����,��i+2n��ʾi����� 
	for(int k=1;k<=K;++k)
	{
		cin>>f>>x>>y;
		if(x>N or y>N)
		{					//����x��y����ʳ�����е���� 
			++ans;
			continue;
		}
		if(f==1)
		{
			if(find(x)==find(y+N) or find(x)==find(y+N*2)\
			/*or find(y)==find(x+N) or find(y)==find(x+2*N)*/ )
			{			//�����֪x��y,����x��y��,˵�����Ǽٻ� 
				++ans;	//���裺��֪y��x,����y��x�� 
				continue;
			}
			merge(x,y);				//�����滰,��x��y��һ�� 
			merge(x+N,y+N);			//x�������y��������һ�� 
			merge(x+2*N,y+2*N);		//x����к�y�������һ�� 
		}
		else if(f==2)
		{
			if(find(x)==find(y) or find(x)==find(y+N*2)\
				/*or find(y)==find(x+N)*/ )
			{	//�����֪x��y��һ��,����x��y��,˵�����Ǽٻ� 
				++ans;		//���裺��֪x��y 
				continue;
			}
			merge(x,y+N);		//�����滰,��x��y 
			merge(y,x+2*N);		//x�������y������ 
			merge(x+N,y+2*N);//x����г�y�����,����˵y��x����� 
		}
	}
	cout<<ans<<endl;
	return 0;
}
