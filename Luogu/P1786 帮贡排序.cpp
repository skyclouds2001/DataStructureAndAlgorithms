#include<bits/stdc++.h>
using namespace std;
string post[7]={"BangZhu","FuBangZhu","HuFa","ZhangLao",
				"TangZhu","JingYing","BangZhong"};
int postnum[7]={1,2,2,4,7,25,0x7fffffff},n;
struct BANG{
	string name;
	string placepre,placenow;
	int grade;
	long long devo;
	short flow,pp;
}s[120];
bool cmp1(BANG b1,BANG b2)
{
	if(b1.devo==b2.devo)
		return (b1.flow<b2.flow);
	else
		return (b1.devo>b2.devo);
}
bool cmp2(BANG b1,BANG b2)
{
	if(b1.placenow==b2.placenow)
		if(b1.grade==b2.grade)
			return (b1.flow<b2.flow);
		else
			return (b1.grade>b2.grade);
	else
		return (b1.pp<b2.pp);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>s[i].name>>s[i].placepre>>s[i].devo>>s[i].grade,s[i].flow=i;
	sort(s+4,s+n+1,cmp1);
	for(int i=1,j,k=0;i<=n;)
	{
		for(j=postnum[k];j>0&&i<=n;--j)
			s[i].placenow=post[k],s[i].pp=k,++i;
		++k;
	}
	sort(s+1,s+n+1,cmp2);
	for(int i=1;i<=n;++i)
		cout<<s[i].name<<' '<<s[i].placenow<<' '<<s[i].grade<<endl;
	return 0;
}
