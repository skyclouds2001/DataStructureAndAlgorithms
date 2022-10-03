#include<iostream>

//int gcd(int a, int b) {
//	while(a != b) {
//		if(a > b)
//			a = a - b;
//		else if(a < b)
//			b = b - a;
//	}
//	return a;
//}

int gcd(int a, int b) {
	if(a == b)
		return a;
	else if(a > b)
		return gcd(a - b, b);
	else
		return gcd(b, a);
}

int main(int argc, char *argv[]) {
	int x, y;
	std::cin >> x >> y;
	std::cout << gcd(x, y) << std::endl;
	return 0;
} 
