#include<iostream>
#include<string> 
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a>b)	swap(a,b);
	if(b>c)	swap(b,c);
	if(a>b)	swap(a,b);
	if(a+b<=c||a+c<=b||b+c<=a)
	{
		cout<<"Not triangle"<<endl;
		return 0;
	}
	if(a*a+b*b==c*c)
		cout<<"Right triangle"<<endl;
	if(a*a+b*b>c*c)
		cout<<"Acute triangle"<<endl;
	if(a*a+b*b<c*c)
		cout<<"Obtuse triangle"<<endl;
	if(a==b||b==c||a==c)
		cout<<"Isosceles triangle"<<endl;
	if(a==b&&b==c&&a==c)
		cout<<"Equilateral triangle"<<endl;
	return 0;
}
