#include<iostream>
#include<cstring>
using namespace std;
char s[300];
int k,n;
int main()
{
	cin>>s>>k;
	n=strlen(s);
	int i,j;
	while(k>0)
	{
		i=1;
		while(s[i-1]<=s[i]&&i<=n)	++i;	//逻辑优化 
		j=i-1;
		while(j<n)
			s[j]=s[j+1],++j;
		--k;
		--n;
	}
	for(i=0;i<=n&&s[i]=='0';++i);
	if(s[i]=='\0')	//0情况判断 
		cout<<0<<endl;
	else
		cout<<s+i<<endl;
	return 0;
}
