#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;
    while (n) {
        v.push_back(n % 10);
        n /= 10;
    }

    for (int i = v.size() - 1; i < v.size(); --i) {
        if (v[i] > 4)
            --v[i];
    }

    int ans = 0;
    for (int i = v.size() - 1; i < v.size(); --i) {
        ans = ans * 9 + v[i];
    }
    cout << ans << endl;

    return 0;
}
