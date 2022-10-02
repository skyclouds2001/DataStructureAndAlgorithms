#include<string>
#include<iostream>   
using namespace std;
string f(int x)
{
	if(x==2)	return "2";
	string ans;
	int a[20]={0},i,xx=x;
	for(i=1;xx>0;i++)
	{
		a[i]=xx%2;
		xx=xx>>1;
	}
	int n=i-1;
	for(i=n;i>=1;i--)
	{
		if(i!=n&&a[i]==1)	ans=ans+"+";
		if(i==2&&a[i]==1)	ans=ans+"2";
		else if(i==1&&a[i]==1)	ans=ans+"2(0)";
		else if(a[i]==1)
		{
			ans=ans+"2("+f(i-1)+")";
		}
		//cout<<"x="<<x<<" i="<<i<<" ans="<<ans<<endl;
	}
	//cout<<"x="<<x<<" ans="<<ans<<endl;
	return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<f(n)<<endl;
    return 0;
}
