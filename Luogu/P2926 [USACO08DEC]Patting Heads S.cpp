#include<cstdio>
#include<iostream>
using namespace std;
int f[1000003],N,a[100003],m;	//N<=100000
int num[1000003];
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		scanf("%d",&a[i]),++num[a[i]],m=max(m,a[i]);
	for(int i=1;i<=m;i++)
        if(num[i]!=0)
        	for(int j=i;j<=m;j+=i)
				f[j]+=num[i];
    for(int i=1;i<=N;i++)
		printf("%d\n",f[a[i]]-1);
	return 0;
}
