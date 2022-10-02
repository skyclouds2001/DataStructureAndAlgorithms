#include<iostream>
#include<cstring>
#include<cctype>
#include<cstdio>
using namespace std;
int main()
{
	short p1,p2,p3,k,len;
	char s[6500]={'\0'},ls[6500]={'\0'},op[6500]={'\0'},t;
	cin>>p1>>p2>>p3;
	scanf("%s",s);
	for(int i=1;s[i+1]!='\0';i++)
	{
		if(s[i]=='-'&&s[i+1]>s[i-1])
		{
			if(!((isdigit(s[i+1])&&isdigit(s[i-1]))||(isalpha(s[i+1])&&isalpha(s[i-1]))))
				continue;
			len=s[i+1]-s[i-1];
			if(len==1)
			{
				strcpy(ls,s+i+1);
				strcpy(s+i,ls);
				memset(ls,'\0',6500*sizeof(char));
			}
			else
			{
				len--;
				if(p1==3)
				{
					for(int i=0,k=0;i<len*p2;i++,k++)
						op[k]='*';
				}
				if(p1==2)
				{
					t=s[i-1]+1;
					(islower(t))?(t=t-'a'+'A'):1;
					(p3==2)?(k=p2*len-1):(k=0);
					for(int j=0;j<len;j++)
					{
						for(int p=0;p<p2;p++)
						{
							op[k]=t;
							(p3==2)?(k--):(k++);
						}
						t++;
					}
				}
				if(p1==1)
				{
					t=s[i-1]+1;
					(isupper(t))?(t=t-'A'+'a'):1;
					(p3==2)?(k=p2*len-1):(k=0);
					for(int j=0;j<len;j++)
					{
						for(int p=0;p<p2;p++)
						{
							op[k]=t;
							(p3==2)?(k--):(k++);
						}
						t++;
					}
				}
				strcpy(ls,s+i+1);
				strcpy(s+i,op);
				strcpy(s+i+strlen(op),ls);
				memset(ls,'\0',6500*sizeof(char));
				memset(op,'\0',6500*sizeof(char));
			}
		}
	}
	printf("%s",s);
	return 0;
}
