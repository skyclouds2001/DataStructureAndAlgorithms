#include<iostream>
using namespace std;
int s1,s2,s3,ans,maxs,count[100];
int main()
{
	cin>>s1>>s2>>s3;
	for(int i=1;i<=s1;++i)
		for(int j=1;j<=s2;++j)
			for(int k=1;k<=s3;++k)
				++count[i+j+k];
	for(int i=0;i<100;++i)
		if(maxs<count[i])
			maxs=count[i],ans=i;
	cout<<ans<<endl;
	return 0;
}
