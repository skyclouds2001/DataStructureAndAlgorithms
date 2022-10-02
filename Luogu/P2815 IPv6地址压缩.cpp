#include<iostream>
#include<cstdio>
using namespace std;
char s[100];
bool f[8];
int main()
{
	scanf("%s",s);
	for(int i=0;i<8;++i)
	{
		bool t=true;
		for(int j=0;j<4;++j)
			if(s[i*5+j]!='0')
				t=false;
		if(t)
			f[i]=true;
	}
	int maxl=-1,maxr=-1,maxlen=-1;
	int l=-1,r=-1,len=-1;
	for(int i=0;i<8;++i)
	{
		if(f[i])
		{
			if(l<0)
			{
				l=i;	r=i;
				len=1;
			}
			else
			{
				r=i;
				len++;
			}
			if(len>maxlen)
			{
				maxl=l;	maxr=r;
				maxlen=len;
			}
		}
		else
		{
			l=-1;	r=-1;
			len=-1;
		}
	}
	//cout<<maxl<<' '<<maxr<<endl;
	for(int i=0,j=0;i<maxl;++i)
	{
		j=0;
		while(s[i*5+j]=='0'&&j<4)	++j;
		if(j==4)	cout<<'0';
		for(;j<4;++j)	cout<<s[i*5+j];
		if(i<maxl-1) cout<<':';
	}
	if(maxlen>0)	cout<<"::";
	for(int i=maxr+1,j=0;i<8;++i)
	{
		j=0;
		while(s[i*5+j]=='0'&&j<4)	++j;
		if(j==4)	cout<<'0';
		for(;j<4;++j)	cout<<s[i*5+j];
		if(i<7)	cout<<':';
	}
	return 0;
}
