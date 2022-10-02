#include<iostream>
using namespace std;
struct student{
	int id,score1,score2;
	double score3;
	bool flag;
	void print(bool f)
	{
		if(f)
			cout<<"Excellent"<<endl;
		else
			cout<<"Not excellent"<<endl;
	}
}s[1003];
int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>s[i].id>>s[i].score1>>s[i].score2;
		s[i].score3=s[i].score1*0.7+s[i].score2*0.3;
		if(s[i].score1+s[i].score2>140&&s[i].score3>=80)
			s[i].flag=true;
		else
			s[i].flag=false;
		s[i].print(s[i].flag);
	}
	return 0;
}
