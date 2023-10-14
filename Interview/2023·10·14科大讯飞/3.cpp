#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int n;
vector<int> a;
int s;

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> s;

    unordered_set<int> set(a.begin(), a.end());

    int total = n - 1;

    for (auto c: set) {
        if (c >= s || c <= 0) {
            continue;
        }

        if (c * 2 == s) {
            total -= 1;
        } else if (set.count(s - c) == 1) {
            total -= 1;
        } else {
            total -= 2;
        }
    }

    cout << total << endl;

    return 0;
}
