#include<iostream>
#include<cstdio>
using namespace std;
char s[302],t;
int sn;
int main()
{
	while((t=getchar())!='@'&&sn>=0)
	{
		if(t=='(')
			s[sn]=t,sn++;
		else if(t==')')
			s[sn]=0,sn--;
	}
	if(sn==0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
