#include<stdio.h>
#include<math.h>
#include<memory.h>
int main()
{
	char t=0;
	int x=0,n=0,a=0;
	long long sum=0,ans=0;
	while(scanf("%d",&x)!=EOF)
	{
		getchar();
		t=getchar();
		while(t!='\n'&&t!=EOF)
		{
			if(t=='-'||t>='0'&&t<='9')
			{
				ungetc(t,stdin);
				scanf("%d",&a);
				ans=ans*x+sum;
				sum=sum*x+a;
			}
			t=getchar();
		}
		printf("%d\n",ans);
		sum=0;	ans=0;
	}
	return 0;
}
/*
Sample Input
7
1 -1
2
1 1 1
Sample Output
1
5
*/
