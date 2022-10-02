#include<iostream>
using namespace std;
int main()
{
	for(int i=100,j;i<=333;++i)
	{
		bool s[10]={false};
		j=1;
		s[i/100]=true;
		s[i%10]=true;
		s[i/10%10]=true;
		s[2*i/100]=true;
		s[2*i%10]=true;
		s[2*i/10%10]=true;
		s[3*i/100]=true;
		s[3*i%10]=true;
		s[3*i/10%10]=true;
		for(j=1;j<10&&s[j];++j);
		if(j==10)
			cout<<i<<' '<<2*i<<' '<<3*i<<endl;
	}
	return 0;
}
