#include<bits/stdc++.h>
using namespace std;
int k,b,x1_d,y1_d,x2_d,y2_d;
double l,s,kk;
char ss[100];
int main()
{
	cin>>ss;
	for(int i=0,f=0;i<strlen(ss);++i)
	{
		if(isdigit(ss[i])&&f==1)
			b*=10,b+=(ss[i]-'0');
		else if(isdigit(ss[i])&&f==0)
			k*=10,k+=(ss[i]-'0');
		else if(!isdigit(ss[i])&&k!=0)
			f=1;
	}
	if(b==0)	b=k,k=1;
	cin>>x1_d>>y1_d>>x2_d>>y2_d;
	k=abs(k);	b=abs(b);
	l=b+(double)b/k+sqrt(b*b+(double)b*b/(k*k));
	s=(double)b*b/(2*k);
	kk=(y2_d-y1_d)/(x2_d-x1_d);
	printf("%.4lf %.4lf\n",l,s);
	if(fabs(kk-k)<=1e-4)
		cout<<1<<endl;
	else
		cout<<-1<<endl;
	return 0;
}
