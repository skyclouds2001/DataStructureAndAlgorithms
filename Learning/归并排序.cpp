#include<stdio.h>
void merge(int* a,int p,int q,int r)
{
	int n1=q-p+1,n2=r-q;
	int a1[n1+2],a2[n2+2];
	for(int i=1;i<=n1;i++)
		a1[i]=a[p+i-1];
	for(int j=1;j<=n2;j++)
		a2[j]=a[q+j];
	a1[n1+1]=0x7fffffff;
	a2[n2+1]=0x7fffffff;
	int i=1,j=1;
	for(int k=p;k<=r;k++)
	{
		if(a1[i]<=a2[j])
		{
			a[k]=a1[i];
			i++;
		}
		else
		{
			a[k]=a2[j];
			j++;
		}
	}
}
void mergesort(int *a,int p,int r)
{
	if(p<r)
	{
		int q=(int)((p+r)/2.0);
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		merge(a,p,q,r);
	}
}
int main()
{
	int a[10]={1,4,2,78,5,45,33,34,34,6777};
	mergesort(a,0,9);
	return 0;
 } 
