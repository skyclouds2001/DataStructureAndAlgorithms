#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;

int main(int argc, char const *argv[]) {
    int m, n;
    int x1, x2, y1, y2;
    int x, y;
    while (cin >> m >> n) {
        if (m < 0 || m > 9 || n < 0 || n > 9) {
            cout << -1 << endl;
            m = min(m, 9);
            n = min(n, 9);
        } else {
            cout << 0 << endl;
        }

        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 < 0 || x1 >= m || x2 < 0 || x2 >= m ||
            y1 < 0 || y1 >= n || y2 < 0 || y2 >= n) {
            cout << -1 << endl;
        } else {
            cout << 0 << endl;
        }

        cin >> x;
        if (x < 0 || x >= m || m == 9) {
            cout << -1 << endl;
        } else {
            cout << 0 << endl;
        }

        cin >> y;
        if (y < 0 || y >= n || n == 9) {
            cout << -1 << endl;
        } else {
            cout << 0 << endl;
        }

        cin >> x >> y;
        if (x < 0 || x >= m || y < 0 || y >= n) {
            cout << -1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}
