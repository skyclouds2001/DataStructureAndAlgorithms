#include "iostream"

using namespace std;

int n, l, r;

int main() {
    cin >> n >> l >> r;

    int min = n / r + (n % r != 0 ? 1 : 0);
    int max = n / l;

    cout << min << ' ' << max << endl;

    return 0;
}
