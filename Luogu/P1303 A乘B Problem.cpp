#include<cstdio>
#include<cstring>
using namespace std;
char aa[2010],bb[2010];
short a[2010],b[2010],rpp[4010];
short n1,n2,n;
int main()
{
	scanf("%s",aa);
	scanf("%s",bb);
	n1=strlen(aa);
	n2=strlen(bb);
	for(int i=0;i<n1;i++)
		a[i]=aa[n1-i-1]-'0';
	for(int j=0;j<n2;j++)
		b[j]=bb[n2-j-1]-'0';
	n=n1+n2-1;
	for(int i=0,j,k;i<n1;i++)
	{
		for(j=0,k=i;j<n2&&k<n;j++,k++)
		{
			rpp[k]+=(a[i]*b[j]);
		}
	}
	for(int k=0;k<n;k++)
	{
		if(rpp[k]>9)
		{
			rpp[k+1]+=rpp[k]/10;
			rpp[k]%=10;
		}
	}
	int k=n;
	while(rpp[k]==0&&k>0)	k--;
	for(;k>=0;k--)
		printf("%hd",rpp[k]);
	return 0;
}
