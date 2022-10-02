#include<iostream>
using namespace std;
int n,a[100003],b[100003];
int C[2][100003];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	int *p1=C[0],*p2=C[1],*t;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i]==b[j])
				p2[j]=max(p2[j],p1[j-1]+1);
			else
				p2[j]=max(p2[j-1],p1[j]);
			//cout<<"i="<<i<<" j="<<j<<" dp[i][j]="<<p2[j]<<endl;
		}
		t=p1;	p1=p2;	p2=t;
	}
	cout<<p1[n]<<endl; 
	return 0;
}
