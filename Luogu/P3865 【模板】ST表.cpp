#include<iostream>
#include<cstdio>
using namespace std;
int ST[100000+3][20];
int N,M;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main()
{
	N=read();M=read();
	for(int i=1;i<=N;++i)
		ST[i][0]=read();
	for(int j=1;j<=20;++j)
		for(int i=1;i+(1<<j)-1<=N;++i)
			ST[i][j]=max(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
	for(int i=1,l,r,s;i<=M;++i)
	{
		l=read();	r=read();
		s=__lg(r-l+1);
		printf("%d\n",max(ST[l][s],ST[r-(1<<s)+1][s]));
	}
	return 0;
}
