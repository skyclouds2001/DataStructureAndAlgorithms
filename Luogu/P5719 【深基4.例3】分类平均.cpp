#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,k;
	int na=0,nb=0;
	long long sa=0,sb=0;
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		if(i%k==0)
			sa+=i,++na;
		else
			sb+=i,++nb;
	printf("%.1f %.1f",(double)sa/na,(double)sb/nb);
	return 0;
}
