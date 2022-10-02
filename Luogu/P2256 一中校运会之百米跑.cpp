#include<bits/stdc++.h>
using namespace std;
string stu[20004];
int fa[20004];	//父元素的数组下标
int N,M,K;
int pos(string s)		//返回字符串的下标 
{
	for(int i=1;i<=N;++i)
		if(stu[i]==s)
			return i;
}
int find(string s)		//返回字符串s指向的父元素的数组下标 
{
	int p=pos(s);
	return ((p==fa[p])?p:(fa[p]=find(stu[fa[p]])));
}
void merge(string s1,string s2)		//合并 
{
	fa[find(s2)]=find(s1);
}
int main()
{
	cin>>N>>M;
	for(int i=1;i<=N;++i)
		cin>>stu[i],fa[i]=i;
	string s1,s2;
	for(int i=1;i<=M;++i)
		cin>>s1>>s2,merge(s1,s2);
	cin>>K;
	for(int i=1;i<=K;++i)
		cin>>s1>>s2,cout<<((find(s1)==find(s2))?"Yes.":"No.")<<endl;
	return 0;
}
