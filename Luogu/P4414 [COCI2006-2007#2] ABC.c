#include<stdio.h>
void swap(int *p,int *q)
{
	int t=0;
	t=*p; *p=*q; *q=t;
}
int main()
{
	int a[5]={0};
	char s[5]={0};
	int i=0;
	for(i=0;i<3;i++)	scanf("%d",&a[i]);
	scanf("%s",s);
	(a[0]>a[1])?(swap(a,a+1)):1;
	(a[1]>a[2])?(swap(a+1,a+2)):1;
	(a[0]>a[1])?(swap(a,a+1)):1;
	for(i=0;i<3;i++)
	{
		switch(s[i])
		{
			case 'A':printf("%d ",a[0]);break;
			case 'B':printf("%d ",a[1]);break;
			case 'C':printf("%d ",a[2]);break;
		}
	}
	return 0;
}
