#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

short T;
short n;
vector<short> s;
short a, b, c;

int main() {
    cin >> T;
    for (short k = 0; k < T; ++k) {
        cin >> n;
        s.clear();
        s.resize(n);
        for (short k = 0; k < n; ++k) {
            cin >> s[k];
        }
        cin >> a >> b >> c;

        sort(s.begin(), s.end());

        short mid = (n & 1) ? s[n / 2] : ((s[n / 2 - 1] + s[n / 2]) / 2);
        int sum = 0;
        for (short k = 0; k < n; ++k) {
            sum += s[k];
        }
        short min = s.at(0), max = s.at(s.size() - 1);

        cout << ((mid >= a || sum / n >= b || (sum - min - max) / (n - 2) >= c) ? "Yes" : "No") << endl;
    }

    return 0;
}
