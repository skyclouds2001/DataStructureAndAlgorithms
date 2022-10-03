#include<iostream> 
using namespace std;
int main()
{
	int a[17]={0,13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int sum;
	for(int i=1;i<=16;i++)
	{
		int t=0;
		for(int j=i;j<=16;j++)
		{
			t+=a[j];
			if(t>sum)
				sum=t;
		}
	}
	cout<<sum<<endl;
	return 0;
}
