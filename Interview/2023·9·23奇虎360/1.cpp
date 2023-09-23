#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int C(int n, int m) {
    int ans = 1;
    for(int i = n; i >= m; --i) {
        ans *= i;
    }
    return ans;
}

int main() {
    int T;
    cin >> T;

    for (int k = 0; k < T; ++k) {
        int n, x;
        vector<int> a;

        cin >> n >> x;
        for (int k = 0, t; k < n; ++k) {
            cin >> t;
            a.push_back(t);
        }

        const int rq = (n + 1) / 2;
        int ans = 0;

        sort(a.begin(), a.end());

        cout << ans << endl;
    }

    return 0;
}
