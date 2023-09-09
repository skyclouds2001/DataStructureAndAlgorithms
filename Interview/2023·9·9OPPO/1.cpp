#include <iostream>

using namespace std;

int n;
int a[100000 + 1];

int main() {
    int c = 0;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        if (a[i] % 2 == 1) {
            ++c;
        }
    }

    if (n == 3) {
        cout << (c == 1 || c == 3 ? "YES" : "NO") << endl;
    } else {
        cout << (c > 0 ? "YES" : "NO") << endl;
    }

    return 0;
}
