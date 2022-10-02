#include<iostream>
#include<cstring>
using namespace std;
short n,r,m,rmb[103],rp[103],t[103];
int dpgf[103][103],dpt[103][103];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>rmb[i]>>rp[i]>>t[i];
	cin>>m>>r;
	for(int i=1;i<=n;i++)
	{
		for(int j=r;j>=rp[i];j--)
		{
			for(int k=m;k>=rmb[i];k--)
			{
				if(dpgf[j][k]==dpgf[j-rp[i]][k-rmb[i]]+1)
				{
					if(dpt[j][k]>dpt[j-rp[i]][k-rmb[i]]+t[i])
						dpt[j][k]=dpt[j-rp[i]][k-rmb[i]]+t[i];
				}
				else if(dpgf[j][k]<dpgf[j-rp[i]][k-rmb[i]]+1)
				{
					dpgf[j][k]=dpgf[j-rp[i]][k-rmb[i]]+1;
					dpt[j][k]=dpt[j-rp[i]][k-rmb[i]]+t[i];
				}
			}
		}
	}
	cout<<dpt[r][m]<<endl;
	return 0;
}
