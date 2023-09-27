#include "iostream"
#include "cmath"

using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    int v[6] = {
            0 + abs(y - x) + abs(z - y),
            0 + abs(z - x) + abs(y - z),
            0 + abs(x - y) + abs(z - x),
            0 + abs(z - y) + abs(x - z),
            0 + abs(y - z) + abs(x - y),
            0 + abs(x - z) + abs(y - x),
    };

    int ans = 0x7fffffff;

    for (int i = 0; i < 6; ++i) {
        ans = min(ans, v[i]);
    }

    cout << ans << endl;

    return 0;
}
