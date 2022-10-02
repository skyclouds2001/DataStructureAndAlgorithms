#include<bits/stdc++.h>
using namespace std;
int N,M,P,Q;
int A[10002],B[10002];
bool a[10002],b[10002];
int na,nb;
int find(int x,int *s)
{
	return (x==s[x])?x:(s[x]=find(s[x],s));
}
void merge(int x,int y,int *s)
{
	s[find(y,s)]=find(x,s);
}
int main()
{
	cin>>N>>M>>P>>Q;
	for(int i=1;i<=N;++i)
		A[i]=i;
	for(int i=1;i<=M;++i)
		B[i]=i;
	for(int i=1,x,y;i<=P;++i)
		cin>>x>>y,merge(x,y,A);
	for(int i=1,x,y;i<=Q;++i)
		cin>>x>>y,merge(-x,-y,B);
	for(int i=1,p=find(A[1],A);i<=N;++i)
		if(p==find(A[i],A))
			++na;
	for(int i=1,p=find(B[1],B);i<=M;++i)
		if(p==find(B[i],B))
			++nb;
	cout<<min(na,nb)<<endl;
	return 0;
}
