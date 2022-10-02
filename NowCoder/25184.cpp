#include<iostream>
#include<cstdio>
using namespace std;

int T, n, t, ans;
int a[200 + 1];
int dp[200 + 1];

int main() {
	scanf_s("%d", &T);

	for (int k = 1; k <= T; ++k) {
		memset(a, 0, sizeof(a));
		scanf_s("%d%d", &n, &t);

		for (int i = 1; i <= n; ++i) {
			scanf_s("%d", &a[i]);
		}

		for (int i = 1; i <= n; ++i) {
			for (int j = t; j >= 0; --j) {
				dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
			}
		}

		for (int i = 1; i <= t; ++i) {
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}

	return 0;
}