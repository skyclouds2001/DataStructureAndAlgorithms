#include<iostream>
#include<string>
#include<cmath>
using namespace std;
struct student{
	string name;
	int chinese,math,english,all;
}stu[1003];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>stu[i].name>>stu[i].chinese>>stu[i].math>>stu[i].english;
		stu[i].all=stu[i].chinese+stu[i].math+stu[i].english;
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(fabs(stu[i].chinese-stu[j].chinese)<=5&&\
				fabs(stu[i].math-stu[j].math)<=5&&\
				fabs(stu[i].english-stu[j].english)<=5&&\
				fabs(stu[i].all-stu[j].all)<=10)
			cout<<stu[i].name<<' '<<stu[j].name<<endl;
		}
	}
	return 0;
}
