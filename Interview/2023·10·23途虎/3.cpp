#include <iostream>

using namespace std;

int x, y;

int ans;

int main() {
    cin >> x >> y;

    for (int i = 1, v;; ++i) {
        v = (1 + i) * i / 2;

        if (v > x + y) {
            ans = -1;
            break;
        }
        if (v == x + y) {
            if (x <= i) {
                ans = 1;
            } else {
                ans = -1;
            }
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
