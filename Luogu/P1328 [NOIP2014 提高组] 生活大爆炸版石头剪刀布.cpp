#include<iostream>
#include<cstdio>
using namespace std;
int N,NA,NB,wina,winb;
int na[202],nb[202],a,b;
int main()
{
	cin>>N>>NA>>NB;
	for(int i=0;i<NA;i++)
		cin>>na[i];
	for(int i=0;i<NB;i++)
		cin>>nb[i];
	for(int i=0;i<N;i++)
	{
		a=na[i%NA];	b=nb[i%NB];
		if(a==b)
			;
		else if(a==3&&(b==0||b==1)||a==4&&(b==2||b==3)||a==2&&b==0)
			winb++;
		else if(b-a==1&&b!=4||b==4&&(a==0||a==1))
			winb++;
		else
			wina++;
		//cout<<"i="<<i<<' '<<"a="<<a<<' '<<"b="<<b<<' '<<"wina="<<wina<<' '<<"winb="<<winb<<endl;
	}
	cout<<wina<<' '<<winb<<endl;
	return 0;
}
