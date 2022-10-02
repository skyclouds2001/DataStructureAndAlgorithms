#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
short ww11[10000],ll11[10000];
short ww21[5000],ll21[5000];
int main()
{
	int win=0,lose=0,k11=0,k21=0,pw11=0,pl11=0,pw21=0,pl21=0,ww=0,ll=0;
	int n;
	char s[30];
	while(1)
	{
		memset(s,'\0',30*sizeof(char));
		scanf("%s",s);
		n=strlen(s);
		for(int i=0;i<n;i++)
		{
			switch(s[i])
			{
				case 'W':win++;break;
				case 'L':lose++;break;
				case 'E':goto OUT;
			}
			ww=win-pw11;	ll=lose-pl11;
			if(ww-ll>=2||ll-ww>=2)
			{
				if(ww>=11||ll>=11)
				{
					ww11[k11]=ww;	ll11[k11]=ll;
					k11++;
					pw11=win;	pl11=lose;
				}
			}
			ww=win-pw21;	ll=lose-pl21;
			if(ww-ll>=2||ll-ww>=2)
			{
				if(ww>=21||ll>=21)
				{
					ww21[k21]=ww;	ll21[k21]=ll;
					k21++;
					pw21=win;	pl21=lose;
				}
			}
		}
	}
		OUT:
		ww11[k11]=win-pw11;	ll11[k11]=lose-pl11;
		k11++;
		ww21[k21]=win-pw21;	ll21[k21]=lose-pl21;
		k21++;
	for(int i=0;i<k11;i++)
		printf("%d:%d\n",ww11[i],ll11[i]);
	printf("\n");
	for(int i=0;i<k21;i++)
		printf("%d:%d\n",ww21[i],ll21[i]);
	return 0;
}
