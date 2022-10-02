#include<iostream>
#include<string>
using namespace std;
struct student{
	string name;
	int chinese,math,english,all;
}stu[1003];
int main()
{
	int n,maxi;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>stu[i].name>>stu[i].chinese>>stu[i].math>>stu[i].english;
		stu[i].all=stu[i].chinese+stu[i].math+stu[i].english;
		if(stu[i].all>stu[maxi].all)	maxi=i;
	}
	cout<<stu[maxi].name<<' '<<stu[maxi].chinese<<' '<<stu[maxi].math<<' '<<stu[maxi].english<<endl;
	return 0;
}
