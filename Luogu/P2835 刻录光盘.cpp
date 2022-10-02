#include<iostream>
using namespace std;
int n,fa[204],ans;
bool flag[204];
int find(int x)
{
	return (x==fa[x])?x:(fa[x]=find(fa[x]));
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		fa[i]=i;
	for(int i=1,x,y;i<=n;++i)
	{
		y=find(i);
		while(true)
		{
			cin>>x;
			if(x==0)
				break;
			flag[x]=true;
			fa[find(x)]=y;
		}
	}
	for(int i=1;i<=n;++i)
		if(fa[i]==i or not flag[i])
			++ans;
	cout<<ans<<endl;
	return 0;
}
/*���ǲ�����Щ����㣨����33������һ�������һ��ÿһ������û��ֱϵ
�ĸ���,�����ĸ����鼯ûɶ����

���O(n)O(n) ɨһ���ʱ������жϣ������û��ֱϵ���׵ģ�ֱ�Ӽ�
һ�����������������Ҳ��һ��*/
