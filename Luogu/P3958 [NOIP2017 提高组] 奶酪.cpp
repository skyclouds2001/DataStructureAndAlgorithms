#include<iostream>
#include<cmath>
using namespace std;
int T,n;
int f1[1004],f2[1004],top,bot;
long long fa[1004],h,r;
bool flag;
struct POINT{
	long long x,y,z;
}p[1004];
inline long long dis(POINT p1,POINT p2)
{
	return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z);
}
int find(int x)
{
	return (x==fa[x])?x:(fa[x]=find(fa[x]));
}
int main()
{
	cin>>T;
	for(int k=1;k<=T;++k)
	{
		cin>>n>>h>>r;
		top=0,bot=0;
		flag=false;
		for(register int i=1;i<=n;++i)
			fa[i]=i;
		for(register int i=1;i<=n;++i)
		{
			cin>>p[i].x>>p[i].y>>p[i].z;
			if(p[i].z+r>=h)
				f1[++top]=i;
			if(p[i].z-r<=0)
				f2[++bot]=i;
			for(int j=1,ii,jj;j<i;++j)
				if(dis(p[i],p[j])<=r*4*r&&((ii=find(i))!=(jj=find(j))))
					fa[jj]=ii;
		}
		for(register int i=1;i<=top&&(!flag);++i)
		{
			for(register int j=1;j<=bot&&(!flag);++j)
			{
				if(find(f1[i])==find(f2[j]))
					flag=true;
			}
		}
		if(flag)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
