#include<cstdio>
#include<deque>
using namespace std;
int a[2000000+4],n,m;
deque<int> d;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		if(i==1)
			printf("0\n");
		else
			printf("%d\n",a[d.front()]);
		if(not d.empty() and i-d.front()>=m)
			d.pop_front();
		while(not d.empty() and a[d.back()]>a[i])
			d.pop_back();
		d.push_back(i);
	}
	return 0;
}
