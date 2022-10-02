#include<cstdio>
#include<iostream>
using namespace std;
int N,end;
long long length;
long long s[100002],t[100002];
void sort_fast(int l,int r)
{
	if(l>=r)  return;		
	else
	{
		int i=l,j=r,x=s[i],y=t[i];
		while(i<j)
		{		
			for(;s[j]>x&&i<j;j--)	;
			if(i<j)	{	s[i]=s[j];	t[i]=t[j];	}
			for(;s[i]<=x&&i<j;i++)	;
			if(i<j)	{	s[j]=s[i];	t[j]=t[i];	}
		}
		s[i]=x;		t[i]=y;
		sort_fast(l,i-1);
		sort_fast(i+1,r);
	}
}
int main()
{
	cin>>N;
	for(int i=0;i<N;i++)
		scanf("%lld%lld",&s[i],&t[i]);
	sort_fast(0,N-1);
	end=t[0]+1;
	length=t[0]-s[0]+1;
	for(int i=1;i<N;i++)
	{
		if(end<=s[i])
		{
			length+=(t[i]-s[i]+1);
			end=t[i]+1;
		}
		else if(end<t[i])	//end>s[i]
		{
			length+=(t[i]-end+1);
			end=t[i]+1;
		}
		else if(end>=t[i])	//end>s[i]
			continue;
	}
	cout<<length<<endl;
	return 0;
}
