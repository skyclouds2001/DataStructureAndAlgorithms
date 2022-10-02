#include<iostream>
#include<cctype>
using namespace std;
char s[32];
short num[16],alpha[16];
int main()
{
	scanf("%s",s);
	for(int i=0,j=0,k=0;i<32;i++)
	{
		if(isupper(s[i]))
		{
			alpha[j]=s[i]-'A'+1;		//1-26
			j++;
		}
		else if(islower(s[i]))
		{
			alpha[j]=s[i]-'a'+1001;		//1001-1026
			j++;
		}
		else if(isdigit(s[i]))
		{
			num[k]=s[i]-'0';
			k++;
		}
	}
	for(int i=0;i<16;i++)
	{
		alpha[i]=alpha[i]+num[i];
		if(alpha[i]>26&&alpha[i]<1000)	alpha[i]=alpha[i]-26+1000+1;
		else if(alpha[i]>1026)	alpha[i]=alpha[i]-26-1000+1;
	}
	for(int i=1,k;i<=4;i++)
	{
		for(int j=0;j<4;j++)
		{
			k=i*4-j-1;
			if(alpha[k]>1000)
				cout<<(char)(alpha[k]-1001+'a');
			else
				cout<<(char)(alpha[k]-1+'A');
		}
	}
	return 0;
}
