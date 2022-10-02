#include<cstdio>
using namespace std;
const long long MOD = 998244353;
int n;
long long ans;

long long f(int a, int n) {
	
	if(n == 0)
		return 1;
	
	long long base = a;
	int t = n;
	long long ans = 1;
	
	while(t != 0) {
		
		if(t & 1) {
			ans *= base;
			ans %= MOD;
		}
		
		
		t >>= 1;
		base *= base;
		base %= MOD;
	}
	
	ans %= MOD;
	return ans;
}

long long c(int m, int n) {
	long long ans = 1;
	
	for(int i = 0; i < m; ++i) {
		ans *= (n - i);
		ans /= (i + 1);
		ans %= MOD;
	}
	
	return ans;
}

int main() {
	
	scanf("%d", &n);
	
	if(n == 1 || n == 2)
		ans = 0;
	else if(n & 1)
		ans = f(2, n - 2);
	else
		ans = f(2, n - 2) - c(((n - 2) / 2), (n - 2));
	
	printf("%lld", ans);
	
	return 0;
}
