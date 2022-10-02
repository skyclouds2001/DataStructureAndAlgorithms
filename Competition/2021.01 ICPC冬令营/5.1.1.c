#include<stdio.h>
int main()
{
	int N=0;
	scanf("%d",&N);
	int a[N];
	int i=0,j=0,t=0;
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	for(i=1;i<N;i++)
	{
		t=a[i];
		j=i-1;
		while(t<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=t;
	}
	printf("%d",a[N/2]);
	return 0;
}
