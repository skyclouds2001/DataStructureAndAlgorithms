#include<stdio.h>
#include<math.h>
long long i=0,j=0,k=0;
int main()
{
	short T=0;
	scanf("%hd",&T);
	long long n[T];
	int p=0;
	_Bool f=0;
	for(i=0;i<T;i++)
		scanf("%hd",&n[i]);
	for(i=0;i<T;i++)
	{
		k=n[i];
		p=0;	
		while((k=k-(int)pow(2,p))>0)
		{
			p++;
			~f;
		}
		if(f) printf("1\n");
		else printf("0\n");
	}
	return 0;	
}
