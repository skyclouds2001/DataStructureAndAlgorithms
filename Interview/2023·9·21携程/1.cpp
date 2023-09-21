#include "cstdio"
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

int n;
vector<int> a;
vector<int> b;

int main() {
    scanf("%d", &n);
    a.resize(n);
    b.resize(n);
    for (int i = 0, t; i < n; ++i) {
        scanf("%d", &t);
        a[i] = t;
        b[i] = t;
    }

    std::sort(b.begin(), b.end());

    for (int i = n - 1; i >= 0; --i) {
        int j = i;

        while (b[j] == a[i] && j >= 0) {
            --j;
        }

        swap(b[i], b[j]);
    }

    for (auto t: b) {
        printf("%d ", t);
    }

    return 0;
}
