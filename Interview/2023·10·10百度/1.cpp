#include "cstdio"
#include "unordered_map"
#include "algorithm"

using namespace std;

const int N = 100000 + 1;

int n, m, k;
int b[N], a[N];

unordered_map<int, int> maps;

int ans;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int k = 1; k <= n; ++k) {
        scanf("%d%d", b + k, a + k);
    }

    for (int k = 1; k <= n; ++k) {
        if (maps.count(b[k]) == 0) {
            maps[b[k]] = 0x7fffffff;
        }

        if (maps[b[k]] > a[k]) {
            maps[b[k]] = a[k];
        }
    }

    for (auto c: maps) {
        ans += c.second;
    }

    printf("%d\n", min(ans, k));

    return 0;
}
