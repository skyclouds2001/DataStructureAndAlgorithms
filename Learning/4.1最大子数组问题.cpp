#include<iostream>
using namespace std;
struct maxsum{
	int left;
	int right;
	int sum;
};
maxsum worksum(const int *a,const int left,const int mid,const int right)
{
	int leftsum=-0x7fffffff,rightsum=-0x7fffffff;
	int maxleft=mid,maxright=mid;
	for(int i=mid,sum=0;i>=left;i--)
	{
		sum+=a[i];
		if(sum>leftsum)
		{
			leftsum=sum;
			maxleft=i;
		}
	}
	for(int i=mid+1,sum=0;i<=right;i++)
	{
		sum+=a[i];
		if(sum>rightsum)
		{
			rightsum=sum;
			maxright=i;
		}
	}
	maxsum ans={maxleft,maxright,leftsum+rightsum};
	return ans;
}
maxsum findsum(const int *a,const int left,const int right)
{
	maxsum ans={left,right,0};
	if(left==right)
		ans.sum=a[left];
	else
	{
		int mid=(left+right)/2;
		maxsum lans=findsum(a,left,mid);
		maxsum rans=findsum(a,mid+1,right);
		maxsum mans=worksum(a,left,mid,right);
		if(lans.sum>=rans.sum&&lans.sum>=mans.sum)
			ans.sum=lans.sum;
		else if(rans.sum>=lans.sum&&rans.sum>=mans.sum)
			ans.sum=rans.sum;
		else
			ans.sum=mans.sum;
	}
	return ans;
}
int main()
{
	int a[17]={0,13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	maxsum ans=findsum(a,0,16);
	cout<<ans.sum<<endl;
	return 0;
}
