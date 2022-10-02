#include<iostream>
using namespace std;
int T,n;
int k[16];
int main()
{
	scanf("%d",&T);
	k[1]=2;
	for(int i=1;i<15;i++)
	{
		k[i+1]=2*k[i];
		k[i]--;
	}
	k[15]--;
	for(int j=0,i;j<T;j++)
	{
		scanf("%d",&n);
		for(i=2;i<=15;i++)
		{
			if(n%k[i]==0)
				break;
		}
		if(i<16)	printf("YE5\n");
		else	printf("N0\n");
	}
	return 0;
}
