#include<stdio.h>
#include<string.h>
int main()
{
	short n=0,maxi=0;
	scanf("%hd",&n);
	short b[n];
	char a[n][500];
	short i=0,j=0,t=0;
	for(i=0;i<n;i++)
	{
		scanf("%s",a[i]);
		b[i]=strlen(a[i]);
	}
	for(maxi=0,i=1;i<n;i++)
	{
		if(b[maxi]<b[i])  maxi=i;
		else if(b[maxi]==b[i])
		{
			if(strcmp(a[i],a[maxi])>0)  maxi=i;
		}
	}
	printf("%hd\n",maxi+1);
	printf("%s",a[maxi]);
	return 0;
}
