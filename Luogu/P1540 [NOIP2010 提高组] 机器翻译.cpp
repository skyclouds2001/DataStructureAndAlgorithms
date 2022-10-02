#include<iostream>
#include<cstdio>
using namespace std;
int M,N,a[1005],count,vs,ve;
int main()
{
	cin>>M>>N;
	for(int i=0,t;i<N;i++)
	{
		cin>>t;
		for(int j=vs;j<ve;j++)
		{
			if(a[j]==t)	goto CON;
		}
		if(ve<M+vs)
		{
			a[ve]=t;
			ve++;
			count++;
		}
		else
		{
			a[ve]=t;
			ve++;
			vs++;
			count++;
		}
		CON:;
	}
	cout<<count<<endl;
	return 0;
}
