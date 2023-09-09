#include <cstdio>

using namespace std;

int n;
int a[100000 + 1];
long long sum;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        sum += a[i];
    }

    // ave = sum / n
    // ave' = (sum + 100 * k) / (n + k) > 90
    // => k > 9 * n - sum / 10

    double k = (double)n * 9 - sum / 10;

    printf("%lld", (double)(long long)k == k ? (long long)k : ((long long)k + 1));

    return 0;
}
