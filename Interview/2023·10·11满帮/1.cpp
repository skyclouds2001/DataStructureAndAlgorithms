#include <iostream>

using namespace std;

int main() {
    int t, n, d;

    cin >> t;

    for (int k = 0; k < t; ++k) {
        cin >> n >> d; // 4 3

        long long m = n / d; // 1
        long long b = (1 + m - 1) * ((m - 1) * d) / 2; // 0
        long long a = (n - m * d + 1) * m; // 2
        long long s = a + b;

        cout << s << endl;
    }

    return 0;
}
