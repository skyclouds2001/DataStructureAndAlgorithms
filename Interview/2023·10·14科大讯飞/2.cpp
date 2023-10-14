#include <iostream>

using namespace std;

int n;
int a[1000], b[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    int l = 0, r = n - 1;
    while (l < n && a[l] == b[l]) {
        ++l;
    }
    while (r >= 0 && a[r] == b[r]) {
        --r;
    }

    if (l > r) {
        cout << (n * (n + 1) / 2) << endl;
        return 0;
    } else if (l == r) {
        cout << 0 << endl;
        return 0;
    }

    int s = l, e = r;
    while (s <= r && e >= l && a[s] == b[e]) {
        ++s;
        --e;
    }

    if (s > r && e < l) {
        int ans = 1;
        int s = l - 1, e = r + 1;
        while (s >= 0 && e < n && a[s] == a[e] && b[s] == b[e]) {
            --s;
            ++e;
            ++ans;
        }
        cout << ans << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
