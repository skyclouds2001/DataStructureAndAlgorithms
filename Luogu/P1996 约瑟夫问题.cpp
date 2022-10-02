#include<iostream>
using namespace std;
bool flow[200];
int n,m,p,k,c;
int main()
{
	cin>>n>>m;
	c=1;
	while(k<n)
	{
		p++;
		p%=n; 
		if(!flow[p])
			c++;
		else
			continue;
		if(c==m)
		{
			flow[p]=true;
			cout<<p+1<<' ';
			k++;
			c=0;
		}
	}
	return 0;
} 
