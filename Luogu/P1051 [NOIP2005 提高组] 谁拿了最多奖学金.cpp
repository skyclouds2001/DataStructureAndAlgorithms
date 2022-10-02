#include<iostream>
#include<string>
using namespace std;
short N,maxi;
long long allmoney;
struct student{
	string name;
	short averscore,classscore,paper;
	char isofficer,iswest;
	int money;
}stu[103];
int main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>stu[i].name>>stu[i].averscore>>stu[i].classscore>>\
		stu[i].isofficer>>stu[i].iswest>>stu[i].paper;
		stu[i].money=0;
		if(stu[i].averscore>80&&stu[i].paper>=1)
			stu[i].money+=8000;
		if(stu[i].averscore>85&&stu[i].classscore>80)
			stu[i].money+=4000;
		if(stu[i].averscore>90)
			stu[i].money+=2000;
		if(stu[i].averscore>85&&stu[i].iswest=='Y')
			stu[i].money+=1000;
		if(stu[i].classscore>80&&stu[i].isofficer=='Y')
			stu[i].money+=850;
		allmoney+=stu[i].money;
		if(stu[maxi].money<stu[i].money)
			maxi=i;
	}
	cout<<stu[maxi].name<<endl<<stu[maxi].money<<endl<<allmoney<<endl;
	return 0;	
}
