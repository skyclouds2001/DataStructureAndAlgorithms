#include<cstdio>
using namespace std;
int n;
int a[1000000 + 3], dp[1000000 + 3];
long long ans1 = -1000000, ans2 = -1000000;

long long max(long long a, int b) {
	return (a > b)?a:b;
}

int main() {
	
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &(a[i]));
	
	for(int i = 1; i <= n; ++i) {
		if(dp[i - 1] >= 0)
			dp[i] = dp[i - 1] + a[i];
		else
			dp[i] = a[i];
		
		ans1 = max(ans1, dp[i]);
		if(ans1 != dp[i])
			ans2 = max(ans2, dp[i]);
	}
	
	printf("%lld", ans1 + ans2);
	return 0;
}
