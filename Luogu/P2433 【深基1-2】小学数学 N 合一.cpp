#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
    int T;
    cin >> T;
    if (T == 1) {
		cout<<"I love Luogu!"<<endl;
    } else if (T == 2) {
		cout<<6<<" "<<4<<endl;
    } else if (T == 3) {
    	cout<<3<<endl<<12<<endl<<2<<endl;
    } else if (T == 4) {
    	printf("%.3f\n",500.0/3.0);
    } else if (T == 5) {
    	cout<<15<<endl;
    } else if (T == 6) {
    	cout<<sqrt(117)<<endl;
    } else if (T == 7) {
    	cout<<110<<endl<<90<<endl<<0<<endl;
    } else if (T == 8) {
    	const double pi=3.141593;
    	cout<<pi*10<<endl<<pi*25<<endl<<4.0/3.0*pi*125<<endl;
    } else if (T == 9) {
    	cout<<22<<endl;
    } else if (T == 10) {
    	cout<<9<<endl;
    } else if (T == 11) {
    	cout<<100.0/3.0<<endl;
    } else if (T == 12) {
    	cout<<(int)('M'-'A')+1<<endl<<(char)('A'+17)<<endl;
    } else if (T == 13) {
    	const double pi=3.141593;
    	cout<<(int)pow(4.0/3.0*pi*(1000+64),1.0/3.0);
    } else if (T == 14) {
    	cout<<50<<endl;
    }
    return 0;
}
