#include<iostream>
using namespace std;
int L,N;
short f[10005];		//0Ê÷  1Ê÷Ãç  2Ê÷¿Ó 
int flag,begin,end,len,count;
int main()
{
	cin>>L>>N;
	for(int i=0;i<N;i++)
	{
		cin>>flag>>begin>>end;
		if(flag==1)
		{
			for(int j=begin;j<=end;j++)
			{
				if(f[j]==2)	f[j]=1;
			}
		}
		else if(flag==0)
		{
			for(int j=begin;j<=end;j++)
			{
				if(f[j]==1)	count++;
				f[j]=2;
			}
		}
	}
	for(int i=0;i<=L;i++)
	{
		if(f[i]==1)	len++;
	}
	cout<<len<<endl;
	cout<<count<<endl;
	return 0;
}
