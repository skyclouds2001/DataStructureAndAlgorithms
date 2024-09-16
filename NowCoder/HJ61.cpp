#include <iostream>

using namespace std;

int m;
int n;

int find(int m, int n) {
    if (m == 0 || m == 1 || n == 1) {
        return 1;
    }

    if (m < n) {
        return find(m, m);
    }

    return find(m, n - 1) + find(m - n, n);
}

int main(int argc, char const *argv[]) {
    cin >> m >> n;

    cout << find(m, n) << endl;

    return 0;
}
