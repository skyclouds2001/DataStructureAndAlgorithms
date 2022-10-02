#include<iostream>
using namespace std;
int main()
{
	double h,m,bmi;
	cin>>m>>h;
	bmi=m/h/h;
	if(bmi<18.5)
		cout<<"Underweight"<<endl;
	else if(bmi>=18.5 and bmi<24.0)
		cout<<"Normal"<<endl;
	else
		cout<<bmi<<endl<<"Overweight"<<endl;
	return 0;
}
