#include<stdio.h>
#include<string.h>
int main()
{
	int n=0;
	long long day=0;
	int Hy=0,Hm=0,Hd=0;
	char *H[19]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen",\
					"yax","zac","ceh","mac","kankin","muan","pax","koyab",\
					"cumhu","uayet"};
	int Ty=0,Tm=0,Td=0;
	char *T[20]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat",\
					"muluk","ok","chuen","eb","ben","ix","mem","cib","caban",\
					"eznab","canac","ahau"};
	int i=0,j=0,t=0;
	char ls[10]={'\0'};
	scanf("%d",&n);	getchar();
	for(i=0;i<n;i++)
	{
		scanf("%d. %s %d",&Hd,ls,&Hy);	getchar();
		for(j=0;j<19;j++)
		{
			if(!strncmp(ls,H[j],strlen(H[j])))
			{
				Hm=j+1;
				break;
			}
		}
		day=365*Hy+20*(Hm-1)+Hd;
		t=day%260;
		Ty=day/260;
		Tm=t%20+1;
		Td=t%13+1;
		printf("%d %s %d\n\n",Td,T[Tm-1],Ty);
		memset(ls,'\0',10*sizeof(char));
	}
	return 0;
}
