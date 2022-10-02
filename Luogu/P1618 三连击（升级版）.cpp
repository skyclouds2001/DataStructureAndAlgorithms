#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	bool flag=true;
	cin>>a>>b>>c;
	for(int i=100,j;i<=333;++i)
	{
		if(i*b%a!=0||i*c%a!=0||b*i/a>=1000||c*i/a>=1000)
			continue;
		bool s[10]={false};
		j=1;
		s[i/100]=true;
		s[i%10]=true;
		s[i/10%10]=true;
		s[b*i/a/100]=true;
		s[b*i/a%10]=true;
		s[b*i/a/10%10]=true;
		s[c*i/a/100]=true;
		s[c*i/a%10]=true;
		s[c*i/a/10%10]=true;
		for(j=1;j<10&&s[j];++j);
		if(j==10)
			cout<<i<<' '<<b*i/a<<' '<<c*i/a<<endl,flag=false;
	}
	if(flag)	cout<<"No!!!"<<endl;
	return 0;
}
