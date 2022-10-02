#include<bits/stdc++.h>
using namespace std;
int N,M;
int st[1000000+3][21];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main()
{
	N=read();	M=read();
	for(int i=1;i<=N;++i)
		st[i][0]=read();
	for(int j=1;j<=20;++j)
		for(int i=1;i+(1<<j)-1<=N;++i)
			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	for(int i=1,s=__lg(M);i+M-1<=N;++i)
		printf("%d\n",min(st[i][s],st[i+M-(1<<s)][s]));
	return 0;
}
