#include<iostream>
using namespace std;
int P[101],W[101];
int T,E,F,N,M;
int dp[10100];
int main()
{
	cin>>T;		//���������� 
	for(int k=1;k<=T;k++)
	{
		cin>>E>>F;
		cin>>N;		//Ӳ���������� 
		M=F-E;		//Ӳ�������� 
		for(int i=1;i<=N;i++)
			cin>>P[i]>>W[i];	//Ӳ����ֵ|Ӳ������ 
		dp[0]=0;
		for(int i=1;i<=M;i++)	dp[i]=0x0FFFFFFF;
		for(int i=1;i<=N;i++)
		{
			for(int j=W[i];j<=M;j++)
			{
				dp[j]=min(dp[j],dp[j-W[i]]+P[i]);
			}
		}
		if(dp[M]>=0x0FFFFFFF)
			cout<<"This is impossible."<<endl;
		else
			cout<<"The minimum amount of money in the piggy-bank is "<<dp[M]<<"."<<endl;
	}
	return 0;
}
