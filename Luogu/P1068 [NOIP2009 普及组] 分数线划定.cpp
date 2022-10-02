#include<cstdio>
#include<iostream>
using namespace std;
short k[5000],s[5000];
int main()
{
	short m,n;
	short t;
	scanf("%hd%hd",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%hd%hd",&k[i],&s[i]);
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(s[j]<s[j+1]||s[j]==s[j+1]&&k[j]>k[j+1])
			{
				t=s[j];	s[j]=s[j+1];	s[j+1]=t;
				t=k[j];	k[j]=k[j+1];	k[j+1]=t;
			}
		}
	}
	short level=s[(int)(m*1.5)-1],sum=0;
	for(int i=0;s[i]>=level&&i<n;i++)
		sum++;
	printf("%hd %hd\n",level,sum);
	for(int i=0;s[i]>=level&&i<n;i++)
		printf("%hd %hd\n",k[i],s[i]);
	return 0;
 } 
