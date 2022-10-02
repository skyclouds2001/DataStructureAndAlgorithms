#include<iostream>
using namespace std;
int a[100005],n;
int maxlen;
long long sum;
int main()
{
	cin>>n;
	for(int k=0;k<n;k++)
		cin>>a[k];
	maxlen=1;
	for(int i=0,j=1;i<n&&j<n;)
	{
		if(a[j]>=a[j-1])
		{
			maxlen=max(j-i+1,maxlen);
			j++;
		}
		else
		{
			i=j;
			j=i+1;
		}
	}
	sum=(long long)(maxlen+1)*maxlen/2;
	cout<<sum<<endl;
	return 0;
}
